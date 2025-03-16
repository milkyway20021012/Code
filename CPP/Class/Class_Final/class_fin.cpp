// #include <iostream>
// using namespace std;
// class A
// {
// public:
//     // 构造函数 explicit就不再支持隐式类型转换
//     // explicit A(int a1);
//     A(int a1) : _a1(a1) {}
//     // explicit A(int a1, int a2):
//     A(int a1, int a2) : _a1(a1), _a2(a2) {}
//     void Print()
//     {
//         cout << _a1 << " " << _a2 << endl;
//     }
//     int Get() const
//     {
//         return _a1 + _a2;
//     }
// private:
//     int _a1 = 1;
//     int _a2 = 2;
// };
// class B
// {
// public:
//     B(const A &A) : _b(A.Get())
//     {
//     }
// private:
//     int _b = 0;
// };
// int main()
// {
//     // 1 构造一个A的临时对象，在用这个临时对象拷贝给 aa1
//     // 当编译器遇到 连续构造 + 拷贝构造 会优化成直接构造函数
//     A aa1 = 1;
//     aa1.Print();
//     const A &aa2 = 1;
//     // aa1隐式类型转换为b对象 原理跟上面类似
//     B b = aa1;
//     const B &rb = aa1;
//     return 0;
// }

// 实现一个类，计算程序中创建出了多个类对象
// #include <iostream>
// using namespace std;
// class A
// {
// public:
//     A()
//     {
//         ++_scount;
//     }
//     A(const A &t)
//     {
//         ++_scount;
//     }
//     ~A()
//     {
//         --_scount;
//     }
//     static int GetACount()
//     {
//         return _scount;
//     }
// private:
//     // 类里面声明
//     static int
//         _scount;
// };
// // 类外初始化
// int A::_scount = 0;
// int main()
// {
//     cout << A::GetACount() << endl;
//     A a1, a2;
//     A a3(a1);
//     cout << A::GetACount() << endl;
//     cout << a1.GetACount() << endl;
//     // 编译报错：error: '_scount' is a private member of 'A'
//     // cout << A::_scount << endl
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class B; // 因为例子中要传入 B类对象的引用，所以这里要先声明，不然会报错
// class A
// {
//     friend void Func1(const A &aa, const B &bb);
// public:
// private:
//     int _a1 = 1;
//     int _a2 = 2;
// };
// class B
// {
// public:
//     friend void Func1(const A &aa, const B &bb);
//     // func1 既是 A 类的友元 也是 B 类的友元
// private:
//     int _b1 = 3;
//     int _b2 = 4;
// };
// void Func1(const A &aa, const B &bb)
// {
//     cout << aa._a1 << aa._a2 << endl;
//     cout << bb._b1 << bb._b2 << endl;
// }
// int main()
// {
//     A aa1;
//     B bb1;
//     Func1(aa1, bb1);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A
// {
//     friend class B; // 声明 B类 是A类的友元
// private:
//     int _a1 = 1;
//     int _a2 = 2;
// };
// class B
// {
// public:
//     void Func1(const A &aa)
//     {
//         cout << aa._a1 << " " << _b1 << endl;
//     }
//     void Func2(const A &aa)
//     {
//         cout << aa._a2 << " " << _b2 << endl;
//     }
// private:
//     int _b1 = 3;
//     int _b2 = 4;
// };
// int main()
// {
//     A a1;
//     B b1;
//     b1.Func1(a1);
//     b1.Func2(a1);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A
// {
// public:
//     class B
//     {
//     public:
//         void foo(const A &aa)
//         {
//             cout << _k << endl;
//             cout << aa._h << endl;
//         }
//     };
// private:
//     static int _k;
//     int _h = 1;
// };
// int A::_k = 1;
// int main()
// {
//     A a1;
//     cout << sizeof(a1) << endl;
//     A::B b1;
//     b1.foo(a1);
//     return 0;
// }

#include <iostream>
using namespace std;
class A
{
public:
    A(int a = 0) : _a(a)
    {
        cout << "A(int a = 0)调用" << endl;
    }
    ~A()
    {
        cout << "~A()调用" << endl;
    }

private:
    int _a;
};
class Solution
{
public:
    int Sum_Solution(int n)
    {
        return n;
    }
};
int main()
{
    A aa1;
    // A aa1(); //不能这样定义对象，编译器会不知道是函数声明还是对象定义

    A(); // 匿名对象
    A(10);

    Solution().Sum_Solution(10);
    return 0;
}
