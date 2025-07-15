#pragma once
#include <iostream>
using namespace std;

namespace BST
{
    template <class K>
    struct BSTNode
    {
        BSTNode(const K &value) : _left(nullptr), _right(nullptr), _val(value) {}
        BSTNode<K> *_left;
        BSTNode<K> *_right;
        K _val;
    };

    template <class K>
    class BST
    {
        typedef BSTNode<K> *Node;

    public:
        BST() : _root(nullptr) {}

        // 插入節點（不允許重複）
        bool insert(const K &value)
        {
            if (_root == nullptr)
            {
                _root = new BSTNode<K>(value);
                return true;
            }

            Node parent = nullptr;
            Node cur = _root;
            while (cur)
            {
                if (cur->_val < value)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_val > value)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    return false; // 已存在
                }
            }

            // cur 是 nullptr，此時 parent 是插入點的父節點
            Node newNode = new BSTNode<K>(value);
            if (value < parent->_val)
            {
                parent->_left = newNode;
            }
            else
            {
                parent->_right = newNode;
            }

            return true;
        }

        // 查找
        bool find(const K &value)
        {
            Node cur = _root;
            while (cur)
            {
                if (cur->_val < value)
                {
                    cur = cur->_right;
                }
                else if (cur->_val > value)
                {
                    cur = cur->_left;
                }
                else
                {
                    cout << value << " 存在" << endl;
                    return true;
                }
            }
            cout << value << " 不存在" << endl;
            return false;
        }

        // 刪除節點
        bool erase(const K &val)
        {
            if (_root == nullptr)
            {
                return false;
            }

            Node parent = nullptr;
            Node cur = _root;

            while (cur)
            {
                if (cur->_val < val)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_val > val)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    // case 1: 無左子
                    if (cur->_left == nullptr)
                    {
                        if (parent == nullptr)
                        {
                            _root = cur->_right;
                        }
                        else if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else
                        {
                            parent->_right = cur->_right;
                        }
                        delete cur;
                        return true;
                    }
                    // case 2: 無右子
                    else if (cur->_right == nullptr)
                    {
                        if (parent == nullptr)
                        {
                            _root = cur->_left;
                        }
                        else if (parent->_left == cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else
                        {
                            parent->_right = cur->_left;
                        }
                        delete cur;
                        return true;
                    }
                    // case 3: 有左右子
                    else
                    {
                        Node RightMinP = cur;
                        Node RightMin = cur->_right;
                        while (RightMin->_left)
                        {
                            RightMinP = RightMin;
                            RightMin = RightMin->_left;
                        }

                        cur->_val = RightMin->_val;

                        if (RightMinP->_left == RightMin)
                        {
                            RightMinP->_left = RightMin->_right;
                        }
                        else
                        {
                            RightMinP->_right = RightMin->_right;
                        }

                        delete RightMin;
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
        void _InOrder(Node root)
        {
            if (root == nullptr)
                return;

            _InOrder(root->_left);
            cout << root->_val << " ";
            _InOrder(root->_right);
        }

    private:
        Node _root;
    };
}

namespace BST_K_V
{
    template <class K, class V>
    struct BSTNode
    {
        BSTNode(const K &key, const V &val)
            : _left(nullptr), _right(nullptr), _key(key), _val(val) {}

        BSTNode<K, V> *_left;
        BSTNode<K, V> *_right;
        K _key;
        V _val;
    };

    template <class K, class V>
    class BST
    {
        typedef BSTNode<K, V> Node;

    public:
        // 0. 构造
        BST() : _root(nullptr) {}

        // 1. 拷貝构造
        BST(const BST<K, V> &bst)
        {
            _root = Copy(bst._root);
        }

        // 2. 賦值
        BST<K, V> &operator=(BST<K, V> target)
        {
            std::swap(_root, target._root);
            return *this;
        }

        // 3. 析构
        ~BST()
        {
            Destroy(_root);
            _root = nullptr;
        }

        // 插入（不允許重複 key）
        bool insert(const K &key, const V &val)
        {
            if (_root == nullptr)
            {
                _root = new Node(key, val);
                return true;
            }

            Node *parent = nullptr;
            Node *cur = _root;
            while (cur)
            {
                if (key < cur->_key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (key > cur->_key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                {
                    return false; // 重複 key
                }
            }

            Node *newNode = new Node(key, val);
            if (key < parent->_key)
                parent->_left = newNode;
            else
                parent->_right = newNode;

            return true;
        }

        // 查找（根據 key）
        Node *find(const K &key)
        {
            Node *cur = _root;
            while (cur)
            {
                if (key < cur->_key)
                    cur = cur->_left;
                else if (key > cur->_key)
                    cur = cur->_right;
                else
                {
                    return cur;
                }
            }
            return nullptr;
        }

        // 刪除（根據 key）
        bool erase(const K &key)
        {
            if (_root == nullptr)
                return false;

            Node *parent = nullptr;
            Node *cur = _root;

            while (cur)
            {
                if (key < cur->_key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (key > cur->_key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                {
                    // case 1: 無左子
                    if (cur->_left == nullptr)
                    {
                        if (parent == nullptr)
                            _root = cur->_right;
                        else if (parent->_left == cur)
                            parent->_left = cur->_right;
                        else
                            parent->_right = cur->_right;

                        delete cur;
                        return true;
                    }
                    // case 2: 無右子
                    else if (cur->_right == nullptr)
                    {
                        if (parent == nullptr)
                            _root = cur->_left;
                        else if (parent->_left == cur)
                            parent->_left = cur->_left;
                        else
                            parent->_right = cur->_left;

                        delete cur;
                        return true;
                    }
                    // case 3: 有左右子
                    else
                    {
                        Node *RightMinP = cur;
                        Node *RightMin = cur->_right;
                        while (RightMin->_left)
                        {
                            RightMinP = RightMin;
                            RightMin = RightMin->_left;
                        }

                        cur->_key = RightMin->_key;
                        cur->_val = RightMin->_val;

                        if (RightMinP->_left == RightMin)
                            RightMinP->_left = RightMin->_right;
                        else
                            RightMinP->_right = RightMin->_right;

                        delete RightMin;
                        return true;
                    }
                }
            }

            return false; // key 不存在
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
                return;

            _InOrder(root->_left);
            cout << root->_key << ":" << root->_val << " ";
            _InOrder(root->_right);
        }

        Node *Copy(Node *root)
        {
            if (root == nullptr)
                return nullptr;

            Node *newRoot = new Node(root->_key, root->_val);
            newRoot->_left = Copy(root->_left);
            newRoot->_right = Copy(root->_right); // 修正此行錯字
            return newRoot;
        }

        void Destroy(Node *root)
        {
            if (root == nullptr)
                return;

            Destroy(root->_left);
            Destroy(root->_right);
            delete root;
        }

    private:
        Node *_root;
    };
}