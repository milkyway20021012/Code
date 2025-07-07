// #include <iostream>
// #include <typeinfo>
// using namespace std;
// // 函數模板
// template <typename T>
// void Swap(T &x1, T &x2)
// {
//     T tmp = x1;
//     x1 = x2;
//     x2 = tmp;
// }

// // 類模板 => 當類使用了類模板後，類名 != 類型
// template <class T>
// class A
// {
// public:
//     void Print()
//     {
//         cout << " This is a" << typeid(T).name() << " template" << endl;
//     }
// };

// // 模板進階
// // 1. 非類型模板 => 主要使用的場景：需要設立一個靜態的內容
// /*
// 非類型模板參數的限制
//     1. 只有整型家族(包括char) 才可以使用非類型模板參數
//     2. 非類型模板參數需要在編譯階段就能確認結果
//     3. 非類型模板參數具有常性，無法被更改
// */

// // namespace test
// // {
// //     template <class T, size_t N = 10>
// //     class test_class
// //     {
// //     public:
// //         void modify()
// //         {
// //             N = 0;
// //         }
// //     private:
// //         T a[N];
// //     };
// // }
// void swap(int &a, int &b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
// int main()
// {
//     // int a = 1, b = 2;
//     // double c = 20.1, d = 30.2;
//     // Swap(a, b);
//     // Swap(c, d);
//     // cout << a << " " << b << endl;
//     // cout << c << " " << d << endl;
//     int a = 1, b = 2;
//     swap(a, b);
//     cout << a << " " << b << endl;
//     return 0;
// }

#include <iostream>
#include "../include/Date.h"

// template <class T>
// bool Less(T left, T right)
// {
//     return left < right;

// }
// // 函數模板特化
// /*
// 函数模板的特化步骤：

// 1.  必须要先有一个基础的函数模板
// 2.  关键字template后面接一对空的尖括号<>
// 3.  函数名后跟一对尖括号，尖括号中指定需要特化的类型 => 不可以是未知的類型
// 4.  函数形参表: 必须要和模板函数的基础参数类型完全相同，如果不同编译器可能会报一些奇怪的错误

// */
// template <>
// bool Less<Date*>(Date* d1, Date* d2){
//     return *d1 < *d2;
// }
// int main()
// {
//     cout << Less(1, 2) << endl; // 可以比较，结果正确
//     Date d1(2022, 7, 7);
//     Date d2(2022, 7, 8);
//     cout << Less(d1, d2) << endl; // 可以比较，结果正确
//     Date *p1 = &d1;
//     Date *p2 = &d2;
//     cout << Less(p1, p2) << endl; // 可以比较，结果错误
//     return 0;
// }

template <class T1, class T2>
class Data
{
public:
    Data() { cout << "基礎模板類" << endl; }

private:
    T1 _d1;
    T2 _d2;
};
template <typename T1, typename T2>
class Data<T1 *, T2 *>
{
public:
    Data() { cout << "Data<T1*, T2*>" << endl; }

private:
    T1 _d1;
    T2 _d2;
};
// 两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data<T1 &, T2 &>
{
public:
    Data(const T1 &d1, const T2 &d2)
        : _d1(d1), _d2(d2)
    {
        cout << "Data<T1&, T2&>" << endl;
    }

private:
    const T1 &_d1;
    const T2 &_d2;
};

// 将第二个参数特化为int
template <class T1>
class Data<T1, int>
{
public:
    Data() { cout << "Data<T1, int>" << endl; }

private:
    T1 _d1;
    int _d2;
};

void test2()
{
    Data<double, int> d1;        // 调用特化的int版本
    Data<int, double> d2;        // 调用基础的模板
    Data<int *, int *> d3;       // 调用特化的指针版本
    Data<int &, int &> d4(1, 2); // 调用特化的指针版本
}

int main()
{
    test2();
    return 0;
}