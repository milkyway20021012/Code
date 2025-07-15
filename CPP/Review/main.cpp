#include <iostream>
using namespace std;

// namespace Extending_Namespace
// {
//     void func1()
//     {
//         cout << "你可以对我进行拓展" << endl;
//     }
// }
// namespace Extending_Namespace
// {
//     void func2()
//     {
//         cout << "我是新定义的函数" << endl;
//     }
// }
// int main()
// {
//     Extending_Namespace::func1();
//     Extending_Namespace::func2();
//     return 0;
// }

// namespace Namespace_Alias
// {
//     void func1()
//     {
//         cout << "Namespace_Alias" << endl;
//     }
// }
// namespace NA = Namespace_Alias;
// int main()
// {
//     Namespace_Alias::func1();
//     NA::func1();
//     return 0;
// }

// Anonymous namespace
// namespace
// {
//     int value = 10;
// }
// int value = 20;
// int main()
// {
//     // Accessing anonymous namespace variable
//     cout << value;
//     return 0;
// }

// int main()
// {
//     int a = 6, b = 4;
//     // Binary AND operator
//     cout << "a & b is " << (a & b) << endl;
//     // Binary OR operator
//     cout << "a | b is " << (a | b) << endl;
//     // Binary XOR operator
//     cout << "a ^ b is " << (a ^ b) << endl;
//     // Left Shift operator
//     cout << "a << 1 is " << (a << 1) << endl;
//     // Right Shift operator
//     cout << "a >> 1 is " << (a >> 1) << endl;
//     // One’s Complement operator
//     cout << "~(a) is " << ~(a);
//     return 0;
// }

// class C
// {
// };
// int main()
// {
//     cout << sizeof(C) << endl;
//     return 0;
// }

// void Print(int Num = 5)
// {
//     cout << Num << endl;
// }
// int main()
// {
//     Print(10);
//     Print(5);
//     return 0;
// }

// void num(int a = 5)
// {
//     cout << a << endl;
// }
// void num(int a, double b)
// {
//     cout << a << b << endl;
// }
// int main()
// {
//     int a = 20;
//     double b = 30;
//     num(a);
//     num(a, b);
//     return 0;
// }

// int main()
// {
//     int arr[] = {10, 20, 'a', 50};
//     for (auto &e : arr)
//     {
//         cout << e << endl;
//     }
//     return 0;
// }

// int firstRepeated(vector<int> &arr)
// {
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         for (int j = i + 1; j < arr.size(); ++j)
//         {
//             if (arr[i] == arr[j])
//             {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int arr[] = {1, 5, 3, 4, 3, 5, 6};
//     vector<int> v;
//     for (auto &e : arr)
//     {
//         v.push_back(e);
//     }
//     cout << firstRepeated(v) << endl;
//     return 0;
// }

// int main()
// {
//     int a = 10;
//     int *b = &a; // b是指针变量 类型是int类型的指针，其储存a的地址 ( & => 如果跟着指针，代表取地址 )
//     /*
//     如果要访问 a 的地址中的内容 => *指针变量 => 解引用
//     */
//     cout << &a << endl;
//     cout << b << endl;
//     cout << a << endl;
//     cout << *b << endl;
//     return 0;
// }

// int main()
// {
//     int a = 10;
//     // 空指针
//     void *myptr = &a;
//     cout << "The value of a is: " << a << endl;
//     cout << "The Address of a is  " << myptr << endl;
// }

// 函数指针

// typedef int (*Operation)(int&, int&);
// int add(int &a, int &b)
// {
//     return a + b;
// }
// int mul(int &a, int &b)
// {
//     return a * b;
// }
// int calculator(int &a, int &b, Operation op)
// {
//     return op(a, b);
// }
// int main()
// {
//     int a = 5, b = 10;
//     cout << calculator(a, b, add);
//     return 0;
// }


