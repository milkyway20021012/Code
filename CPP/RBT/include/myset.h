#include "RBT.h"
#include <iostream>
using namespace std;

namespace bit {

// set集合模板类，K为元素类型
template <class K> class set {
  // 仿函数，直接返回key本身
  // 设计原因：set的元素就是key，不需要从pair中提取d
  struct SetKeyOfT {
    const K &operator()(const K &key) { return key; }
  };

public:
  // 迭代器类型定义，直接复用RBT的迭代器
  typedef typename RBT<K, K, SetKeyOfT>::Iterator iterator;
  typedef typename RBT<K, K, SetKeyOfT>::ConstIterator const_iterator;

  // begin/end接口，支持范围for遍历
  iterator begin() { return _t.begin(); }
  iterator end() { return _t.end(); }
  const_iterator begin() const { return _t.begin(); }
  const_iterator end() const { return _t.end(); }

  // 插入元素，返回插入结果
  pair<iterator, bool> insert(const K &key) { return _t.insert(key); }
  // 查找元素，返回迭代器
  iterator find(const K &key) { return _t.find(key); }

private:
  RBT<K, K, SetKeyOfT> _t; // 底层用红黑树实现
};

// 打印set内容，逆序输出
void Print(const set<int> &s) {
  set<int>::const_iterator it = s.end();
  while (it != s.begin()) {
    --it;
    // *it += 2; // set元素不可修改
    cout << *it << " ";
  }
  cout << endl;
}

// 测试set功能
void test_set() {
  set<int> s;
  int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
  for (auto e : a)
    s.insert(e);
  for (auto e : s) {
    cout << e << " ";
  }
  cout << endl;
  Print(s);
}

} // namespace bit