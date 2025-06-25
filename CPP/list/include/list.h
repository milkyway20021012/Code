#include <iostream>
#include <assert.h>
// list 不是隨機訪問 => 隨機訪問就是可以利用[]隨意存取某一塊記憶體 (前提是這個記憶體需要是合法的)
using namespace std;
namespace bit
{
    template <class T>
    struct list_node
    {
        list_node<T> *_next;
        list_node<T> *_prev;
        T _val;
        list_node(const T val = T()) : _next(nullptr), _prev(nullptr), _val(val)
        {
        }
    };
    template <class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef list_node<T> Node;
        typedef __list_iterator<T, T &, T *> self;
        Node *_node;
        __list_iterator(Node *node) : _node(node)
        {
        }
        // typedef __list_iterator<T, T &, T*> iterator;
        // typedef __list_iterator<T, const T &, const T*> const_iterator;
        Ref operator*() const
        {
            return _node->_val;
        }
        // 前置++
        self &operator++()
        {
            _node = _node->_next;
            return *this;
        }
        // 後置++
        self &operator++(int)
        {
            Node *tmp = _node;
            _node = _node->_next;
            return tmp;
        }
        // 前置++
        self &operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        // 後置++
        self &operator--(int)
        {
            Node *tmp = _node;
            _node = _node->_prev;
            return tmp;
        }
        bool operator!=(const self &lt) const
        {
            return _node != lt._node;
        }
        Ptr operator->()
        {
            return &_node->_val;
        }
    };
    template <class T>
    class list
    {
        typedef list_node<T> Node;

    public:
        typedef __list_iterator<T, T &, T *> iterator;
        typedef __list_iterator<T, const T &, T *> const_iterator;
        void empty_Init()
        { // 初始化List
            head = new Node;
            head->_next = head;
            head->_prev = head;
            _size = 0;
        }
        list()
        {
            empty_Init();
        }
        // 以一個已經存在的對象對另外一個對象賦值 => 拷貝
        // lt2(lt1) => lt2 = lt1
        list(const list<T> &lt)
        {
            empty_Init();

            for (auto &e : lt)
            {
                push_back(e);
            }
        }

        ~list()
        {
            clear();
            delete head;
            head = nullptr;
        }
        void swap(list<T> lt)
        {
            std::swap(head, lt.head);
            std::swap(_size, lt._size);
        }
        // 以一個已經存在的對象對另外一個存在的對象賦值 => 賦值
        list<T> &operator=(list<T> lt)
        {
            swap(lt);
            return *this;
        }

        // 清除所有數據
        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it); // 因爲erase之後迭代器就會失效了，所以要接收返回值
            }
            _size = 0;
        }
        // Iterator
        iterator begin() const
        {
            return head->_next; // 單參數函數支持隱式類型轉換
        }
        iterator end() const

        {
            return head; // 單參數函數支持隱式類型轉換
        }
        // 運算符重載

        // 增
        void push_back(const T &x)
        {
            // Node *tail = head->_prev;
            // Node *newnode = new Node(x);
            // // 插入數據
            // tail->_next = newnode;
            // newnode->_prev = tail;

            // newnode->_next = head;
            // head->_prev = newnode;

            insert(end(), x);
        }

        void push_front(const T &x)
        {
            insert(begin(), x);
        }
        void pop_back()
        {
            erase(--end());
        }
        void pop_front()
        {
            erase(begin());
        }
        iterator insert(iterator pos, const T &val)
        {
            Node *cur = pos._node;
            Node *prev = cur->_prev;
            Node *newnode = new Node(val);

            prev->_next = newnode;
            newnode->_next = cur;
            newnode->_prev = prev;
            cur->_prev = newnode;
            ++_size;
            return newnode;
        }
        iterator erase(iterator pos)
        {
            assert(pos != end());

            Node *cur = pos._node;
            Node *prev = cur->_prev;
            Node *next = cur->_next;

            prev->_next = next;
            next->_prev = prev;
            delete cur;
            --_size;
            return next;
        }
        size_t size()
        {
            return _size;
        }

    private:
        Node *head;
        size_t _size;
    };
    void test01()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    void test02()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_front(3);
        lt.push_front(4);
        lt.push_front(5);
        lt.push_front(6);

        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;

        lt.pop_back();
        lt.pop_back();
        lt.pop_back();

        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;

        lt.pop_front();
        lt.pop_front();
        lt.pop_front();
        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void test03()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_front(3);
        lt.push_front(6);

        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
        lt.clear();

        lt.push_back(2);
        lt.push_back(5);
        lt.push_back(7);
        lt.push_front(3);
        lt.push_front(6);
        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
        cout << lt.size();
    }

    void test04()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
        list<int> lt2 = lt;
        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void test05()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
        list<int> lt2;
        lt2.push_back(2);
        lt2.push_back(3);
        lt2.push_back(5);
        lt2.push_back(6);
        for (auto e : lt2)
        {
            cout << e << " ";
        }
        cout << endl;

        lt2 = lt;
        for (auto e : lt2)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}