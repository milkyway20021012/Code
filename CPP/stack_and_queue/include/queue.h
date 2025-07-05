#include <iostream>
#include <list>
using namespace std;
namespace bit
{
    template <class T, class Container = deque<T>>
    class queue
    {
    public:
        void push(const T &val)
        {
            _con.push_back(val);
        }
        void pop()
        {
            // _con.pop_back(); // queue為先進先出原則，如果使用pop_front 就無法適配vector -> vector沒有提供頭刪
            // 但強制適配並不好 實際庫中queue是不支持vector的

            // _con.erase(_con.begin());

            _con.pop_front();
        }
        T &front()
        {
            return _con.front();
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

    void test_queue()
    {
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}