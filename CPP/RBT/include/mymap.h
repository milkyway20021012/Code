#include "RBT.h"

/*
实现map和set的步骤：
 1、实现红黑树（修改原本的红黑树结构，将pair<K, V> 改为T）
 2、封装map和set框架，解决KeyOfT
 3、iterator
 4、const_iterator
 5、key不可修改的问题
 6、operator[]
*/

namespace bit {

// map映射模板类，K为key类型，V为value类型
template <class K, class V> class map {
  // 仿函数，从pair<K, V>中提取key
  struct MapKeyOfT {
    const K &operator()(const pair<K, V> &kv) { return kv.first; }
  };

public:
  // 迭代器类型定义，复用RBT的迭代器
  typedef typename RBT<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
  typedef typename RBT<K, pair<const K, V>, MapKeyOfT>::ConstIterator
      const_iterator;

  iterator begin() { return _t.begin(); }
  iterator end() { return _t.end(); }
  const_iterator begin() const { return _t.begin(); }
  const_iterator end() const { return _t.end(); }

  // 下标操作符，若key不存在则插入默认值
  V &operator[](const K &key) {
    pair<iterator, bool> ret = insert(make_pair(key, V()));
    return ret.first->second;
  }

  // 插入键值对
  pair<iterator, bool> insert(const pair<K, V> &kv) { return _t.insert(kv); }
  // 查找key，返回迭代器
  iterator find(const K &key) { return _t.find(key); }

private:
  RBT<K, pair<K, V>, MapKeyOfT> _t; // 底层用红黑树实现
};

}; // namespace bit