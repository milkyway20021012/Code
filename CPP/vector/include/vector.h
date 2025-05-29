#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace bit
{
    template <class T>
    class vector
    {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }

        vector() : _start(nullptr),
                   _finish(nullptr),
                   _end_of_storage(nullptr)
        {
        }
        ~vector()
        {
            if (_start)
            {
                delete[] _start;
                _start = nullptr;
                _finish = nullptr;
                _end_of_storage = nullptr;
            }
        }
        void push_back(const T &x)
        {
            // if (_finish == _end_of_storage)
            // {
            //     // 擴容邏輯
            //     size_t new_capacity = capacity() == 0 ? 4 : capacity() * 2;
            //     reserve(new_capacity);
            // }
            // *_finish = x;
            // ++_finish;

            insert(end(), x);
        }
        void reserve(size_t n)
        {
            if (n > capacity()) // n 如果大於有效空間 就要擴容
            {
                size_t sz = size();
                T *tmp = new T[n];
                if (_start)
                {
                    memcpy(tmp, _start, sizeof(T) * sz);
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + sz; // 不能直接調用size() 會崩潰
                _end_of_storage = _start + n;
            }
        }

        size_t capacity()
        {
            return _end_of_storage - _start;
        }
        size_t size()
        {
            return _finish - _start;
        }
        T &operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }

        iterator insert(iterator pos, const T &x)
        {
            assert(pos >= _start && pos <= _finish);
            if (_finish == _end_of_storage)
            {
                size_t len = pos - _start; // 保存pos的位置
                // 擴容邏輯
                size_t new_capacity = capacity() == 0 ? 4 : capacity() * 2;
                reserve(new_capacity);
                // 解決迭代器失效問題
                pos = _start + len;
            }

            iterator _end = _finish - 1;
            while (_end >= pos)
            {
                *(_end + 1) = *_end;
                --_end;
            }
            *pos = x; // pos的類型是 T* 用解引用就可以直接改變pos指向的位置的值

            ++_finish;
            return pos;
        }
        void erase()
        {
        }

    private:
        iterator _start;          // a
        iterator _finish;         // size
        iterator _end_of_storage; // capacity
    };
    void print(const vector<int> &v)
    {
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void test01()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        // for (auto e : v)
        // {
        //     cout << e << " ";
        // }

        for (size_t i = 0; i < v.size(); ++i)
        {
            v[i]++;
        }
        print(v);
    }
    void test02()
    {

        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(3);
        v.push_back(3);
        v.push_back(3);
        v.push_back(3);

        vector<int>::iterator pos = v.begin() + 3;
        v.insert(pos, 100);
        print(v);
        // insert後迭代器可能會失效 (因爲擴容)
        // insert後就不要使用此形參迭代器(如下) => 高危行為
        *pos += 10;
        print(v);
    }
}
