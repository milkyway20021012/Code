#include <iostream>
using namespace std;

namespace OpenAddress {
// 仿函數
template <class K> struct HashFunc {
  size_t operator()(const K &key) {
    return (size_t)key; // 把 key 轉成整數 ( 為了處理 key 非整的情況 =>
                        // 因爲要取模，非整沒辦法取模 )
    // 如果是自定義類型，也可以將賅仿函數進行特化 來處理自定義類型轉整的問題
  }
};
template <> struct HashFunc<string> {
  size_t operator()(const string &key) {
    size_t hash = 0;
    for (auto ch : key) {
      hash = hash * 131 + ch;
    }
    return hash;
  }
};

enum State { EMPTY, EXISTED, DELETED };

template <class K, class V> struct HashData {
  pair<K, V> _kv;
  State _state = EMPTY;
};

template <class K, class V, class Hash = HashFunc<K>> class HashTable {
public:
  // 這裡提供sgi版本的哈希表使⽤的⽅法，给了⼀个近似2倍的质数表，每次去质数表获取扩容后的⼤⼩
  inline unsigned long __stl_next_prime(unsigned long n) {
    // Note: assumes long is at least 32 bits.
    static const int __stl_num_primes = 28;
    static const unsigned long __stl_prime_list[__stl_num_primes] = {
        53,        97,         193,        389,       769,       1543,
        3079,      6151,       12289,      24593,     49157,     98317,
        196613,    393241,     786433,     1572869,   3145739,   6291469,
        12582917,  25165843,   50331653,   100663319, 201326611, 402653189,
        805306457, 1610612741, 3221225473, 4294967291};
    const unsigned long *first = __stl_prime_list;
    const unsigned long *last = __stl_prime_list + __stl_num_primes;
    const unsigned long *pos = lower_bound(first, last, n);
    // 如果 n 的值超出 [first,last) 的最大值 => return 最後一個元素的下一個位置;
    // 如果小於 return 第一個元素的位置
    return pos == last ? *(last - 1) : *pos;
  }
  HashTable() { _table.resize(__stl_next_prime(0)); }
  bool insert(const pair<K, V> &kv) {
    // 插入時先確定該值是否已存在表中
    if (find(kv.first)) {
      return false;
    }
    // 先判斷當前的負載因子大小( N(數據個數) / M(表大小) )
    if (_n * 10 / _table.size() >= 7) { // 這裡我們將負載因子控制在0.7
      // 擴容的邏輯就是先開空間 把元素 _table 中的元素插入到新開的空間中
      // 再將新的空間和舊的空間交換
      HashTable<K, V, Hash> newht;
      newht._table.resize(__stl_next_prime(_table.size() + 1));
      for (size_t i = 0; i < _table.size(); ++i) {
        if (_table[i]._state == EXISTED) {
          newht.insert(_table[i]._kv);
        }
      }
      _table.swap(newht._table);
    }
    // 如果負載因子小於0.7 則直接插入
    Hash hash;
    size_t hash0 = hash(kv.first) % _table.size();
    size_t hashi = hash0;
    size_t i = 1;
    while (_table[hashi]._state == EXISTED) {
      // 線性探測
      hashi = (hash0 + i) % _table.size();
      // 如果是二次探測 就改成 +- i^2

      ++i;
    }
    _table[hashi]._kv = kv;
    _table[hashi]._state = EXISTED;
    ++_n;
    return true;
  }
  HashData<K, V> *find(const K &key) {
    Hash hash;
    size_t hash0 = hash(key) % _table.size();
    size_t hashi = hash0;
    size_t i = 1;
    while (_table[hashi]._state != EMPTY) {
      // 如果找到
      if (_table[hashi]._state == EXISTED && _table[hashi]._kv.first == key) {
        return &_table[hashi];
      }
      // 如果當前的 index 不是目標值 ( 可能是原本就被佔用了，所以要往後找
      // 直到找完整個 _table) => 所以其實開放定址法的效率不及鏈定址法
      hashi = (hash0 + i) % _table.size();
      ++i;
    }
    // while 結束代表沒有找到目標值
    return nullptr;
  }
  bool erase(const K &key) {
    HashData<K, V> *ret = find(key);
    if (ret == nullptr) {
      return false;
    }
    ret->_state = DELETED;
    --_n;
    return true;
  }

private:
  vector<HashData<K, V>> _table;
  size_t _n = 0; // 哈希表中存儲的數據個數
};
void HashTest1() {
  HashTable<int, int> ht;
  ht.insert(make_pair(1, 1));
  ht.insert(make_pair(2, 2));
  ht.insert(make_pair(3, 3));
  ht.insert(make_pair(4, 4));
  ht.insert(make_pair(5, 5));
  ht.insert(make_pair(6, 6));

  ht.erase(2);
  ht.erase(3);
}
void HashTest2() {
  HashTable<string, int> ht;
  ht.insert(make_pair("1111", 1));
  ht.insert(make_pair("2222", 2));
  ht.insert(make_pair("3333", 3));
  ht.insert(make_pair("4444", 4));
  ht.insert(make_pair("5555", 5));
}
} // namespace OpenAddress

namespace HashBucket {
// 仿函数
template <class K> struct HashFunc {
  size_t operator()(const K &key) { return (size_t)key; }
};
template <class K, class V> struct HashData {
  pair<K, V> _kv;
  HashData<K, V> *_next;

  HashData(const pair<K, V> &kv) : _kv(kv), _next(nullptr) {}
};

template <class K, class V, class Hash = HashFunc<K>> class HashTable {
  typedef HashData<K, V> Node;

public:
  inline unsigned long __stl_next_prime(unsigned long n) {
    // Note: assumes long is at least 32 bits.
    static const int __stl_num_primes = 28;
    static const unsigned long __stl_prime_list[__stl_num_primes] = {
        53,        97,         193,        389,       769,       1543,
        3079,      6151,       12289,      24593,     49157,     98317,
        196613,    393241,     786433,     1572869,   3145739,   6291469,
        12582917,  25165843,   50331653,   100663319, 201326611, 402653189,
        805306457, 1610612741, 3221225473, 4294967291};
    const unsigned long *first = __stl_prime_list;
    const unsigned long *last = __stl_prime_list + __stl_num_primes;
    const unsigned long *pos = lower_bound(first, last, n);
    // 如果 n 的值超出 [first,last) 的最大值 => return 最後一個元素的下一個位置;
    // 如果小於 return 第一個元素的位置
    return pos == last ? *(last - 1) : *pos;
  }
  // 初始化
  HashTable() { _table.resize(__stl_next_prime(0)); }
  ~HashTable() {
    for (size_t i = 0; i < _table.size(); ++i) {
      Node *cur = _table[i];
      while (cur) {
        Node *next = cur->_next;
        delete cur;
        cur = next;
      }
      _table[i] = nullptr;
    }
  }
  bool insert(const pair<K, V> &kv) {
    Hash hs;
    size_t hashi = hs(kv.first) % _table.size();
    // 扩容
    // 这路就不用判断负载因子了，因为相同的位置都会像链表一样串接起来
    if (_n == _table.size()) {
      // 怎么扩？
      vector<Node *> newht(__stl_next_prime(_table.size() + 1), nullptr);
      for (size_t i = 0; i < _table.size(); ++i) {
        // 挪动数据
        Node *cur = _table[i];
        while (cur) {
          // 先保留_next;
          Node *next = cur->_next;
          // 将旧表的数据挪动到新表
          size_t hashi = hs(cur->_kv.first) % newht.size();
          cur->_next = newht[hashi];
          newht[hashi] = cur;

          cur = next;
        }
        _table[i] = nullptr;
      }
      _table.swap(newht);
    }
    // 如果有其他数据 => 直接头插
    Node *newnode = new Node(kv);
    newnode->_next = _table[hashi];
    _table[hashi] = newnode;
    ++_n;
    return true;
  }

  Node *find(const K &key) {
    Hash hs;
    size_t hash0 = hs(key) % _table.size();
    Node *cur = _table[hash0];
    while (cur) {
      if (cur->_kv.first == key) {
        return cur;
      }
      cur = cur->_next;
    }
    return nullptr;
  }
  bool erase(const K &key) {
    Hash hs;
    size_t hash0 = hs(key) % _table.size();
    Node *cur = _table[hash0];
    Node *prev = nullptr;
    while (cur) {
      if (cur->_kv.first == key) {
        if (prev == nullptr) { // prev 为空 代表删除的是第一个数据
          _table[hash0] = cur->_next;
        } else {
          prev->_next = cur->_next;
        }
        delete cur;
        --_n;
        return true;
      }
      prev = cur;
      cur = cur->_next;
    }
    return false;
  }

private:
  vector<Node *> _table;
  size_t _n = 0; // 数据个数
};
void HashBucketTest1() {
  HashTable<int, int> ht;
  ht.insert(make_pair(1, 1));
  ht.insert(make_pair(2, 2));
  ht.insert(make_pair(3, 3));
  ht.insert(make_pair(4, 4));
  ht.insert(make_pair(5, 5));
  ht.insert(make_pair(6, 6));
  ht.insert(make_pair(7, 7));
  ht.insert(make_pair(8, 8));
  ht.insert(make_pair(9, 9));
  ht.insert(make_pair(10, 10));
}
void HashBucketTest2() {
  HashTable<int, int> ht;
  ht.insert(make_pair(1, 1));
  ht.insert(make_pair(2, 2));
  ht.insert(make_pair(3, 3));
  ht.insert(make_pair(4, 4));
  ht.insert(make_pair(5, 5));
  ht.erase(2);
  ht.erase(3);
  ht.erase(4);
  ht.erase(5);
  ht.erase(6);
  ht.erase(7);
  ht.erase(8);
  ht.erase(9);
}
} // namespace HashBucket