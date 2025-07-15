#include <iostream>
using namespace std;

template <class K, class V>
struct AVLNode
{
    AVLNode(const pair<K, V> &kv) : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0)
    {
    }
    AVLNode<K, V> *_left;
    AVLNode<K, V> *_right;
    AVLNode<K, V> *_parent;
    pair<K, V> _kv;
    int _bf; // 平衡因子
};

template <class K, class V>
class AVLTree
{
    typedef AVLNode<K, V> Node;

public:
    bool insert(const pair<K, V> &kv)
    {
        // 和二叉樹一樣的邏輯
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
        // 1. 先確定要插入哪裡
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_kv.first < kv)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false; // 我們實現的還是不允許重複插入相同的數據
            }
        }
        // 當上面的邏輯走完，沒有return 代表我們找到了要插入的位置
        // 開始插入的邏輯
        cur = new Node(kv);
        if (parent->_kv.first < kv)
        {
            parent->_right = kv;
        }
        else
        {
            parent->_left = kv;
        }
        cur->_parent = parent;

        // 在這部分要多加一個更新平衡因子 ( 平衡因子 = 右子樹的高度 - 左子樹的高度 )
        while (parent)
        {
            // 更新平衡因子
            if (parent->_left == cur)
            {
                parent->_bf--;
            }
            else
            {
                parent0->_bf++;
            }

            if (parent->_bf == 0)
            {
                // _bf == 0 代表左右子樹已經達到平衡
                break;
            }
            /*
            更新后parent的平衡因子等于1 或 -1，更新前更新中parent的平衡因子变化为0->1 或者 0->-1
            说明更新前parent子树两边一样高，新增的插入结点后，parent所在的子树一边高一边低
            parent所在的子树符合平衡要求，但是高度增加了1，会影响parent的父亲结点的平衡因子，所以要继续向上更新。
            */
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                cur = parent;
                parent = parent->_parent;
            }
            /*
            更新后parent的平衡因子等于2 或 -2，更新前更新中parent的平衡因子变化为1->2 或者 -1->-2
            说明更新前parent子树一边高一边低，新增的插入结点在高的那边
            parent所在的子树高的那边更高了，破坏了平衡，parent所在的子树不符合平衡要求，需要旋转处理
            旋转的目标有两个：1、把parent子树旋转平衡。2、降低parent子树的高度，恢复到插入结点以前的高度
            */
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                // 代表插入後打破了整棵樹的平衡 => 我們要旋轉使其恢復平衡
            }
            else
            {
                assert(false); // 理論上前面的邏輯至少會走其中一條，如果走到else代表前面的邏輯有問題！
            }
        }
    }

private:
    Node *_root = nullptr;
};