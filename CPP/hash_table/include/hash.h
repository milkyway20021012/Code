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
} // namespace OpenAddress
