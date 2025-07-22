#ifndef __RBT_H__
#define __RBT_H__

#include <iostream>
using namespace std;

enum Color { RED, BLACK };

// 红黑树节点结构体模板
// T：节点存储的数据类型（如 pair<K, V> 或自定义 struct）
// 设计原因：模板化节点类型，支持多种数据结构
template <class T> struct RBTNode {
  // 构造函数，初始化数据并默认颜色为红色
  RBTNode(const T &data)
      : _left(nullptr), _right(nullptr), _parent(nullptr), _data(data),
        _color(RED) {}
  RBTNode<T> *_left;   // 指向左孩子节点
  RBTNode<T> *_right;  // 指向右孩子节点
  RBTNode<T> *_parent; // 指向父节点
  T _data;             // 节点存储的数据
  Color _color;        // 节点颜色
  // 设计原因：每个节点需记录父子关系和颜色，便于树结构调整和查找
};

// 红黑树迭代器模板
// T：节点数据类型，Ref/Ptr：引用和指针类型
// 设计原因：支持类似STL的遍历接口
template <class T, class Ref, class Ptr> 
struct RBTreeIterator {
  typedef RBTNode<T> Node;
  typedef RBTreeIterator<T, Ref, Ptr> Self;
  Node *_node; // 当前迭代器指向的节点
  Node *_root; // 整棵树的根节点（用于--到end时定位最大节点）
  RBTreeIterator(Node *node, Node *root) : _node(node), _root(root) {}


  Ref operator*() { return _node->_data; }   // 解引用，返回节点数据
  Ptr operator->() { return &_node->_data; } // 指针访问
  // 前置++，移动到下一个节点（中序遍历）
  Self &operator++() {
    if (_node->_right) {
      Node *leftmost = _node->_right;
      while (leftmost->_left)
        leftmost = leftmost->_left;
      _node = leftmost;
    } else {
      Node *cur = _node, *parent = cur->_parent;
      while (parent && cur == parent->_right) {
        cur = parent;
        parent = parent->_parent;
      }
      _node = parent;
    }
    return *this;
  }
  // 前置--，移动到上一个节点（中序遍历）
  Self &operator--() {
    if (_node == nullptr) {
      Node *rightmost = _root;
      while (rightmost->_right)
        rightmost = rightmost->_right;
      _node = rightmost;
    } else if (_node->_left) {
      Node *rightmost = _node->_left;
      while (rightmost->_right)
        rightmost = rightmost->_right;
      _node = rightmost;
    } else {
      Node *cur = _node, *parent = cur->_parent;
      while (parent && cur == parent->_left) {
        cur = parent;
        parent = parent->_parent;
      }
      _node = parent;
    }
    return *this;
  }
  bool operator!=(const Self &s) const { return _node != s._node; }
  bool operator==(const Self &s) const { return _node == s._node; }
};

// 红黑树主类模板
// K：键类型，T：节点数据类型，KeyOfT：仿函数，从T中提取K
// 设计原因：支持泛型键值类型，KeyOfT适配不同数据结构
template <class K, class T, class KeyOfT> class RBT {
  typedef RBTNode<T> Node;

public:
  typedef RBTreeIterator<T, T &, T *> Iterator;
  typedef RBTreeIterator<T, const T &, const T *> ConstIterator;
  RBT() = default;

  // 返回最左节点的迭代器（begin）
  Iterator begin() {
    Node *leftmost = _root;
    while (leftmost && leftmost->_left)
      leftmost = leftmost->_left;
    return Iterator(leftmost, _root);
  }
  // 返回end迭代器（空节点）
  Iterator end() { return Iterator(nullptr, _root); }
  ConstIterator begin() const {
    Node *leftmost = _root;
    while (leftmost && leftmost->_left)
      leftmost = leftmost->_left;
    return ConstIterator(leftmost, _root);
  }
  ConstIterator end() const { return ConstIterator(nullptr, _root); }

  // 析构函数，递归释放所有节点
  ~RBT() {
    Destroy(_root);
    _root = nullptr;
  }

  // 插入数据，返回插入位置和是否插入成功
  // 设计思路：先查找插入位置，若已存在则返回已存在节点，否则插入并调整红黑树
  pair<Iterator, bool> insert(const T &data) {
    if (_root == nullptr) {
      _root = new Node(data);
      _root->_color = BLACK;
      return make_pair(Iterator(_root, _root), true);
    }
    KeyOfT kot;
    Node *parent = nullptr, *cur = _root;
    while (cur) {
      if (kot(cur->_data) < kot(data)) {
        parent = cur;
        cur = cur->_right;
      } else if (kot(cur->_data) > kot(data)) {
        parent = cur;
        cur = cur->_left;
      } else {
        // 已存在
        return make_pair(Iterator(cur, _root), false);
      }
    }
    cur = new Node(data);
    if (kot(parent->_data) < kot(data))
      parent->_right = cur;
    else
      parent->_left = cur;
    cur->_parent = parent;
    // 插入后调整红黑树性质
    while (parent && parent->_color == RED) {
      Node *grandfather = parent->_parent;
      if (grandfather->_left == parent) {
        Node *uncle = grandfather->_right;
        if (uncle && uncle->_color == RED) {
          parent->_color = BLACK;
          uncle->_color = BLACK;
          grandfather->_color = RED;
          cur = grandfather;
          parent = cur->_parent;
        } else {
          if (cur == parent->_left) {
            RotateR(grandfather);
            parent->_color = BLACK;
            grandfather->_color = RED;
          } else {
            RotateL(parent);
            RotateR(grandfather);
            parent->_color = BLACK;
            grandfather->_color = RED;
          }
          break;
        }
      } else {
        Node *uncle = grandfather->_left;
        if (uncle && uncle->_color == RED) {
          parent->_color = BLACK;
          uncle->_color = BLACK;
          grandfather->_color = RED;
          cur = grandfather;
          parent = cur->_parent;
        } else {
          if (cur == parent->_right) {
            RotateL(grandfather);
            parent->_color = BLACK;
            grandfather->_color = RED;
          } else {
            RotateR(parent);
            RotateL(grandfather);
            parent->_color = BLACK;
            grandfather->_color = RED;
          }
          break;
        }
      }
    }
    _root->_color = BLACK;
    return make_pair(Iterator(cur, _root), true);
  }

  // 查找数据，返回迭代器
  Iterator find(const T &data) {
    KeyOfT kot;
    Node *cur = _root;
    while (cur) {
      if (kot(cur->_data) < kot(data))
        cur = cur->_right;
      else if (kot(cur->_data) > kot(data))
        cur = cur->_left;
      else
        return Iterator(cur, _root);
    }
    return end();
  }

  // 检查红黑树是否满足所有性质
  bool Check(Node *root, int blackNum, const int refNum) {
    if (root == nullptr) {
      if (refNum != blackNum) {
        cout << "存在黑色节点数量不相等的路径" << endl;
        return false;
      }
      return true;
    }
    if (root->_color == RED && root->_parent && root->_parent->_color == RED) {
      cout << "存在连续的红色节点" << endl;
      return false;
    }
    if (root->_color == BLACK)
      blackNum++;
    return Check(root->_left, blackNum, refNum) &&
           Check(root->_right, blackNum, refNum);
  }

  // 判断红黑树是否平衡
  bool IsBalance() {
    if (_root == nullptr)
      return true;
    if (_root->_color == RED) {
      cout << "根节点是红色" << endl;
      return false;
    }
    int refNum = 0;
    Node *left = _root;
    while (left) {
      if (left->_color == BLACK)
        refNum++;
      left = left->_left;
    }
    return Check(_root, 0, refNum);
  }

private:
  // 递归销毁所有节点
  void Destroy(Node *root) {
    if (root == nullptr)
      return;
    Destroy(root->_left);
    Destroy(root->_right);
    delete root;
  }
  Node *_root = nullptr; // 红黑树根节点

  // 右旋操作，维护红黑树平衡
  void RotateR(Node *parent) {
    Node *subL = parent->_left;
    Node *subLR = subL->_right;
    parent->_left = subLR;
    if (subLR)
      subLR->_parent = parent;
    subL->_right = parent;
    Node *parentParent = parent->_parent;
    parent->_parent = subL;
    if (parentParent == nullptr) {
      _root = subL;
      subL->_parent = nullptr;
    } else {
      if (parent == parentParent->_left)
        parentParent->_left = subL;
      else
        parentParent->_right = subL;
      subL->_parent = parentParent;
    }
  }

  // 左旋操作，维护红黑树平衡
  void RotateL(Node *parent) {
    Node *subR = parent->_right;
    Node *subRL = subR->_left;
    parent->_right = subRL;
    if (subRL)
      subRL->_parent = parent;
    subR->_left = parent;
    Node *parentParent = parent->_parent;
    parent->_parent = subR;
    if (parentParent == nullptr) {
      _root = subR;
      subR->_parent = nullptr;
    } else {
      if (parent == parentParent->_right)
        parentParent->_right = subR;
      else
        parentParent->_left = subR;
      subR->_parent = parentParent;
    }
  }
};

#endif // __RBT_H__