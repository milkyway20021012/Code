#pragma once
#include <vector>
using namespace std;

namespace bit
{
    // 仿函數
    template <class T>
    class less
    {
        bool operator()(T &x, T &y)
        {
            return x < y;
        }
    };

    template <class T>
    class Greater
    {
        bool operator()(T &x, T &y)
        {
            return x > y;
        }
    };

    template <class T, class Container = vector<int>, class Compare = less<T>>
    class prioirty_deque
    {
    public:
        template <class InputIterator>
        prioirty_deque(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _con.push_back(*first);
                ++first;
            }
            // 建堆
            // 第一次減 1 => 確認下標 第二次減1 找父親節點
            for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
            {
                AdjustDown(i);
            }
        }

        void pop()
        {
            // 刪除：swap(root,last_leave);

            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            AdjustDown(0);
        }

        void push(const T &val)
        {
            _con.push_back(val);
            AdjustUp(_con.size() - 1);
        }

        void top()
        {
            return _con[0];
        }

        bool empty()
        {
            return _con.empty();
        }

        int size()
        {
            return _con.size();
        }

    private:
        void AdjustUp(int child)
        {
            Compare com;
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                if ((child - 1) > 0 && com(_con[child - 1], _con[child]))
                {
                    --child;
                }
                if (com(_con[child - 1], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }
        void AdjustDown(int parent)
        {
            // 找最大的孩子
            int child = parent * 2 + 1; // 默認最大的孩子是第一個子節點
            while (child < _con.size())
            {
                if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
                {
                    child++;
                }
                if (com(_con[parent], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        Container _con;
    };
    void test01()
    {
        priority_queue<int> pq;
        pq.push(1);
        pq.push(5);
        pq.push(11);
        pq.push(23);
        pq.push(7);

        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}