#include <iostream>
#include <list>
#include <deque>
using namespace std;
namespace bit
{
    // template <class T, class Container = vector<T>>
    template <class T, class Container = deque<T>>
    class stack
    {
    public:
        void push(const T &val)
        {
            _con.push_back(val);
        }
        void pop()
        {
            _con.pop_back();
        }
        T &top()
        {
            return _con.back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

    private:
        Container _con;
    };

    void test_stack()
    {
        stack<int> st1;
        st1.push(1);
        st1.push(2);
        st1.push(3);
        st1.push(4);
        st1.push(5);

        while (!st1.empty())
        {
            cout << st1.top() << " ";
            st1.pop();
        }
        cout << endl;
        stack<int, list<int>>
            st2;
        st2.push(1);
        st2.push(2);
        st2.push(3);
        st2.push(4);
        st2.push(5);

        while (!st2.empty())
        {
            cout << st2.top() << " ";
            st2.pop();
        }
    }
}