#pragma once

#include <string>
#include <assert.h>
// 因爲library中已有string 所以以命名空間做區分

namespace bit
{
    class string
    {
    public:
        typedef char *iterator;
        typedef const char *const_iterator;
        // string() : _size(0), _capacity(0), _str(new char[1])
        // { // 無參
        //     _str[0] = '\0';
        // }
        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        // const_iterator
        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }
        string(const char *str = "") // 帶參
        {
            _size = strlen(str);
            _capacity = strlen(str);
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }
        char *c_str() const // C的string
        {
            return _str;
        }
        size_t size()
        {
            return _size;
        }
        char &operator[](size_t pos) // 重載運算符 讓string也可以像C char 一樣用下標訪問
        {
            assert(pos < _size);
            return _str[pos];
        }
        const char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }
        void reserve(size_t n) // 多少有效字符的空間 假設要10個有效字符會開11個空間
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        // 增刪查改

        // 增
        void push_back(char ch)
        {
            if (_capacity == _size)
            {
                // 2倍擴容
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        void append(const char *str)
        {
            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                // 至少擴容至 _size + len
                reserve(_size + len);
            }
            strcpy(_str + _size, str); // strcpy 會把字符串的'\0'一起拷貝過去
            _size += len;
        }
        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
        string &operator+=(const char *str)
        {
            append(str);
            return *this;
        }

        void insert(size_t pos, size_t n, char ch)
        {
            assert(pos <= _size);
            // 至少擴容至 _size + n
            if (_size + n > _capacity)
            {
                reserve(_size + n);
            }
            // 挪動數據
            size_t end = _size;               // end or pos 類型為 size_t 時 當 pos = 0 會發生問題
            while (end >= pos && end != npos) /* 可以嘗試(int) 強轉pos類型 => 要轉是因爲 end 為int pos為size_t
                                       會發生類型提升(提升至較大的類型 : size_t) 仍然會陷入死循環
                                    */
            {
                _str[end + n] = _str[end];
                --end; // size_t 不會小於 0 所以如果 end 類型為 size_t 會陷入死循環
            }
            for (size_t i = 0; i < n; ++i)
            {
                _str[pos + i] = ch;
            }
            _size += n;
        }
        void insert(size_t pos, const char *str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }
            // 挪動數據
            size_t end = _size;
            while (end >= pos && end != npos)
            {
                _str[end + len] = _str[end];
                --end;
            }
            for (size_t i = 0; i < len; ++i)
            {
                _str[pos + i] = str[i];
            }
            _size += len;
        }

        // 刪除
        void erase(size_t pos = 0, size_t len = npos)
        {
            assert(pos <= _size);
            if (len == npos || pos + len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
                // _str[_size] = '\0';
            }
            else
            {
                size_t end = pos + len;
                while (end <= _size)
                {
                    _str[pos++] = _str[end++];
                }
                _size -= len;
            }
        }

        size_t find(char ch, size_t pos = 0) const
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; ++i)
            {
                if (_str[i] == ch)
                {
                    return i;
                }
            }
            return npos;
        }
        size_t find(const char *str, size_t pos = 0) const
        {
            assert(pos < _size);
            const char *ptr = strstr(_str + pos, str);
            if (ptr)
            {
                return ptr - _str;
            }
            else
            {
                return npos;
            }
        }
        string substr(size_t pos = 0, size_t len = npos) const
        {
            assert(pos < _size);
            size_t n = len;
            if (len == npos || pos + len > _size)
            {
                n = _size - pos;
            }
            string tmp;
            tmp.reserve(n);
            for (size_t i = pos; i < n; ++i)
            {
                tmp += _str[i];
            }
            return tmp;
        }

    private:
        size_t _size;
        size_t _capacity;
        char *_str;

        static size_t npos; // 第二種insert pos = 0 死循環解決方法 : 設定 npos
    };
    // 靜態變量 類內聲明 類外定義
    size_t string::npos = -1;
}