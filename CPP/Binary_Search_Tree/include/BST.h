#pragma once
#include <iostream>
using namespace std;
namespace BSTree
{
    template <class key>
    struct BSTNode
    {
        BSTNode<key> *_left;  // left-child
        BSTNode<key> *_right; // right-child
        key _key;             // value

        BSTNode(const key &val) : _left(nullptr), _right(nullptr), _key(val)
        {
        }
    };

    template <class key>
    class BST
    {
    public:
        typedef BSTNode<key> Node;

        BST() = default;
        // 拷貝構造函數 => 深拷貝
        BST(const BST<key> &bst)
        {
            _root = Copy(bst._root);
        }
        BST<key> &operator=(BST<key> target)
        {
            std::swap(_root, target._root);
            return *this;
        }
        // 析構
        ~BST()
        {
            Destroy(_root);
            _root = nullptr;
        }
        // 我們實現的是值不重複的 所以定義成bool
        bool insert(const key &val)
        {
            if (_root == nullptr)
            {
                _root = new Node(val);
                return true;
            }
            // 如果不是為空 我們要先找要插入的位置
            Node *parent = nullptr;
            Node *cur = _root;

            while (cur)
            {
                if (cur->_key < val)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > val)
                {
                    parent = cur; // 先記錄下來cur的位置(因爲cur是局部變量，我們不能直接把它插入到樹中)
                    cur = cur->_left;
                }
                else
                {
                    return false;
                }
            }
            // 到這裡我們已經找到了葉子的位置(nullptr) 然後我們去建立一個新節點(因爲前面parent 和 cur 都是局部變量，我們不能直接插入)
            cur = new Node(val);
            if (parent->_key < val)
            {
                parent->_right = cur;
            }
            else
            {
                parent->_left = cur;
            }
            return true;
        }
        bool Find(const key &val)
        {
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key < val)
                {
                    cur = cur->_right;
                }
                else if (cur->_key > val)
                {
                    cur = cur->_left;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        bool erase(const key &val)
        {

            Node *parent = nullptr;
            Node *cur = _root;

            while (cur)
            {
                if (cur->_key < val)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > val)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else // cur->_key == val
                {
                    // 刪除目標
                    if (cur->_left == nullptr)
                    {
                        if (parent == nullptr)
                        { // 父節點為空 => root
                            _root = cur->_right;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr)
                    {
                        if (parent == nullptr)
                        {
                            _root = cur->_left;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_left;
                            }
                            else
                            {
                                parent->_right = cur->_left;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else
                    {
                        // 有兩個孩子的情況 => 可以選擇左子樹最大的值或右子樹最小的值 ( 為了滿足BST 左小右大的性質 )
                        Node *RightMinP = cur;        // 當前最小的 val 的父節點
                        Node *RightMin = cur->_right; // 找右子樹最小的 val
                        while (RightMin->_left)
                        { // 右子樹最小的肯定是在 cur->_right 這個節點的左子樹中
                            RightMinP = RightMin;
                            RightMin = RightMin->_left;
                        }
                        cur->_key = RightMin->_key; // 將最小的值給 cur (要刪除的位置) => 交換法

                        if (RightMinP->_left == RightMin) // 判斷RightMin 是RightMinP的左子還是右子
                        {
                            RightMinP->_left = RightMin->_left;
                        }
                        else
                        {
                            RightMinP->_right = RightMin->_right;
                        }
                        delete RightMin; // 刪除節點
                        return true;
                    }
                }
            }

            return false;
        }

        void InOrder()
        {
            _InOrder(_root);
            cout << endl;
        }

    private:
        void _InOrder(Node *root)
        {
            if (root == nullptr)
            {
                return;
            }
            _InOrder(root->_left);
            cout << root->_key << " ";
            _InOrder(root->_right);
        }
        void Destroy(Node *root)
        {
            if (root == nullptr)
            {
                return;
            }
            Destroy(root->_left);
            Destroy(root->_right);
            delete root;
        }
        Node *Copy(Node *root)
        {
            if (root == nullptr)
            {
                return nullptr;
            }
            Node *Newroot = new Node(root->_key);

            Newroot->_left = Copy(root->_left);
            Newroot->_right = Copy(root->_right);

            return Newroot;
        }

    private:
        Node *_root = nullptr;
    };
}

namespace BST_K_V
{
    template <class key, class value>
    struct BSTNode
    {
        BSTNode<key, value> *_left;  // left-child
        BSTNode<key, value> *_right; // right-child
        key _key;                    // value
        value _value;
        BSTNode(const key &k, const value &v) : _left(nullptr), _right(nullptr), _key(k), _value(v)
        {
        }
    };

    template <class key, class value>
    class BST
    {
    public:
        typedef BSTNode<key, value> Node;

        // 我們實現的是值不重複的 所以定義成bool
        bool insert(const key &k, const value &v)
        {
            if (_root == nullptr)
            {
                _root = new Node(k, v);
                return true;
            }
            // 如果不是為空 我們要先找要插入的位置
            Node *parent = nullptr;
            Node *cur = _root;

            while (cur)
            {
                if (cur->_key < k)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > k)
                {
                    parent = cur; // 先記錄下來cur的位置(因爲cur是局部變量，我們不能直接把它插入到樹中)
                    cur = cur->_left;
                }
                else
                {
                    return false;
                }
            }
            // 到這裡我們已經找到了葉子的位置(nullptr) 然後我們去建立一個新節點(因爲前面parent 和 cur 都是局部變量，我們不能直接插入)
            cur = new Node(k, v);
            if (parent->_key < k)
            {
                parent->_right = cur;
            }
            else
            {
                parent->_left = cur;
            }
            return true;
        }
        Node *Find(const key &val)
        {
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key < val)
                {
                    cur = cur->_right;
                }
                else if (cur->_key > val)
                {
                    cur = cur->_left;
                }
                else
                {
                    return cur;
                }
            }
            return nullptr;
        }

        bool erase(const key &val)
        {

            Node *parent = nullptr;
            Node *cur = _root;

            while (cur)
            {
                if (cur->_key < val)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > val)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else // cur->_key == val
                {
                    // 刪除目標
                    if (cur->_left == nullptr)
                    {
                        if (parent == nullptr)
                        { // 父節點為空 => root
                            _root = cur->_right;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr)
                    {
                        if (parent == nullptr)
                        {
                            _root = cur->_left;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_left;
                            }
                            else
                            {
                                parent->_right = cur->_left;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else
                    {
                        // 有兩個孩子的情況 => 可以選擇左子樹最大的值或右子樹最小的值 ( 為了滿足BST 左小右大的性質 )
                        Node *RightMinP = cur;        // 當前最小的 val 的父節點
                        Node *RightMin = cur->_right; // 找右子樹最小的 val
                        while (RightMin->_left)
                        { // 右子樹最小的肯定是在 cur->_right 這個節點的左子樹中
                            RightMinP = RightMin;
                            RightMin = RightMin->_left;
                        }
                        cur->_key = RightMin->_key; // 將最小的值給 cur (要刪除的位置) => 交換法

                        if (RightMinP->_left == RightMin) // 判斷RightMin 是RightMinP的左子還是右子
                        {
                            RightMinP->_left = RightMin->_left;
                        }
                        else
                        {
                            RightMinP->_right = RightMin->_right;
                        }
                        delete RightMin; // 刪除節點
                        return true;
                    }
                }
            }

            return false;
        }

        void InOrder()
        {
            _InOrder(_root);
            cout << endl;
        }

    private:
        void _InOrder(Node *root)
        {
            if (root == nullptr)
            {
                return;
            }
            _InOrder(root->_left);
            cout << root->_key << ":" << root->_value << endl;
            _InOrder(root->_right);
        }
        Node *_root = nullptr;
    };
}