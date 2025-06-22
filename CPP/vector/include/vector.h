#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
// vector 底層邏輯 => 順序表
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
        // 迭代器初始化
        // [first,last)
        template <class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }
        // n 個 val 初始化
        vector(size_t n, T &val = T()) : _start(nullptr),
                                         _finish(nullptr),
                                         _end_of_storage(nullptr)
        {
            resize(n, val);
        }
        vector() : _start(nullptr),
                   _finish(nullptr),
                   _end_of_storage(nullptr)
        {
        }
        // 深拷貝
        vector(const vector<T> &v) : _start(nullptr),
                                     _finish(nullptr),
                                     _end_of_storage(nullptr)
        {
            _start = new T[v.capacity()];
            // memcpy(_start, v._start, sizeof(T) * v.size());
            for (size_t i = 0; i < v.size(); ++i)
            {
                _start[i] = v._start[i];
            }
            _finish = _start + v.size();
            _end_of_storage = _start + v.capacity();
        }

        void swap(vector<T> &v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }
        // 賦值
        // v1 = v2
        vector<T> &operator=(vector<T> v)
        {
            swap(v);
            return *this;
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
        void pop_back()
        {
            erase(--end());
        }
        void reserve(size_t n)
        {
            if (n > capacity()) // n 如果大於有效空間 就要擴容
            {
                size_t sz = size();
                T *tmp = new T[n];
                if (_start)
                {
                    // memcpy(tmp, _start, sizeof(T) * sz); // memcpy 自定義類型會有問題
                    // 調用深拷貝
                    for (size_t i = 0; i < sz; ++i)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + sz; // 不能直接調用size() 會崩潰
                _end_of_storage = _start + n;
            }
        }
        void resize(size_t n, T &val = T())
        {
            if (n < size())
            {
                _finish = size() + 1;
            }
            else
            {
                reserve(n);
                while (_finish != _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }
        size_t size() const
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
        iterator erase(iterator pos)
        {
            assert(pos >= _start && pos <= _finish);
            iterator it = pos + 1;
            while (it != _finish)
            {
                *(it - 1) = *it;
                ++it;
            }
            --_finish;
            return pos;
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
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(6);

        // vector<int>::iterator pos = v.begin() + 3;
        // v.insert(pos, 100);
        // print(v);
        // // insert後迭代器可能會失效 (因爲擴容)
        // // insert後就不要使用此形參迭代器(如下) => 高危行為
        // *pos += 10;
        // print(v);

        // v.erase(v.begin());
        // print(v);

        auto it = v.begin();
        while (it != v.end())
        {
            if (*it % 2 == 0)
            {
                it = v.erase(it);
            }
            else
            {
                it++;
            }
        }
        print(v);
    }
    void test03()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;

        vector<int> v1(v);

        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void test04()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
        vector<int> v1;
        v1 = v;
        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void test05()
    {
        vector<string> v;
        v.push_back("11111");
        v.push_back("22222");
        v.push_back("33333");
        v.push_back("44444");
        v.push_back("55555");
        v.push_back("55555");
        v.push_back("55555");
        v.push_back("55555");
        v.push_back("55555");

        for (auto &e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
