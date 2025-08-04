#include <iostream>
#include <string>
using namespace std;

// class Date {
// public:
//   Date(int year = 2025, int month = 8, int day = 1)
//       : _year(year), _month(month), _day(day) {}
//   void Print() { cout << _year << "-" << _month << "-" << _day << endl; }
// private:
//   int _year;
//   int _month;
//   int _day;
// };
// int main() {
//   // 1. 内置类型使用列表初始化
//   int a{1}; // 补充：列表初始化可以不用写 =
//   int b = {2};
//   cout << a << endl;
//   // 2. 自定义类型
//   Date d1{2025, 7, 31};
//   /*
//   这里的本质是利用 {2025,7,31} 先构造一个Date的临时对象 然后在拷贝给 d
//   -> 但通常编译器会优化两个步骤 => 直接利用 {2025,7,31} 构造
//   */
//   d1.Print();
//   // C++ 98⽀持单参数时类型转换，也可以不⽤ {}
//   Date d2 = {2025};
//   d2.Print();
//   Date d3 = 2025;
//   d3.Print();
//   return 0;
// }

// int main() {
//   vector<int> v{1, 2, 3, 4, 5};
//   for (auto e : v) {
//     cout << e << " ";
//   }
//   cout << endl;
//   unordered_map<string, int> fruit = {{"苹果", 1}, {"木瓜", 2}};
//   for (auto &e : fruit) {
//     cout << e.first << e.second << endl;
//   }
//   return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
//   // 左值：可以取地址
//   // 以下的p、b、c、*p、s、s[0]就是常⻅的左值
//   int *p = new int(0);
//   int b = 1;
//   const int c = b;
//   *p = 10;
//   string s("111111");
//   s[0] = 'x';
//   cout << &c << endl;
//   cout << (void *)&s[0] << endl;
//   // 右值：不能取地址
//   double x = 1.1, y = 2.2;
//   // 以下⼏个10、x + y、fmin(x, y)、string("11111")都是常⻅的右值
//   10;
//   x + y;
//   fmin(x, y);
//   string("11111");
//   // cout << &10 << endl;
//   // cout << &(x+y) << endl;
//   // cout << &(fmin(x, y)) << endl;
//   // cout << &string("11111") << endl;
//   return 0;
// }

// int main() {
//   // 左值：可以取地址
//   // 以下的p、b、c、*p、s、s[0]就是常⻅的左值
//   int *p = new int(0);
//   int b = 1;
//   const int c = b;
//   *p = 10;
//   string s("111111");
//   s[0] = 'x';
//   double x = 1.1, y = 2.2;
//   // 左值引⽤给左值取别名
//   int &r1 = b;
//   int *&r2 = p;
//   int &r3 = *p;
//   string &r4 = s;
//   char &r5 = s[0];
//   // 右值引⽤给右值取别名
//   int &&rr1 = 10;
//   double &&rr2 = x + y;
//   double &&rr3 = fmin(x, y);
//   string &&rr4 = string("11111");
//   // 左值引⽤不能直接引⽤右值，但是const左值引⽤可以引⽤右值
//   const int &rx1 = 10;
//   const double &rx2 = x + y;
//   const double &rx3 = fmin(x, y);
//   const string &rx4 = string("11111");
//   // 右值引⽤不能直接引⽤左值，但是右值引⽤可以引⽤move(左值)
//   int &&rrx1 = move(b);
//   int *&&rrx2 = move(p);
//   int &&rrx3 = move(*p);
//   string &&rrx4 = move(s);
//   string &&rrx5 = (string &&)s;
//   // b、r1、rr1都是变量表达式，都是左值
//   cout << &b << endl;
//   cout << &r1 << endl;
//   cout << &rr1 << endl;
//   // 这⾥要注意的是，rr1的属性是左值，所以不能再被右值引⽤绑定，除⾮move⼀下
//   int &r6 = r1;
//   // int&& rrx6 = rr1;
//   int &&rrx6 = move(rr1);
//   return 0;
// }

// int main() {
//   std::string s1 = "Test";
//   // std::string&& r1 = s1; // 错误：不能绑定到左值
//   const std::string &r2 = s1 + s1; // OK：到 const 的左值引⽤延⻓⽣存期
//   // r2 += "Test"; // 错误：不能通过到 const 的引⽤修改
//   std::string &&r3 = s1 + s1; // OK：右值引⽤延⻓⽣存期
//   r3 += "Test";               // OK：能通过到⾮ const 的引⽤修改
//   std::cout << r3 << '\n';
//   return 0;
// }

// 由于引⽤折叠限定，f1实例化以后总是⼀个左值引⽤
// template <class T> void f1(T &x) {}
// // 由于引⽤折叠限定，f2实例化后可以是左值引⽤，也可以是右值引⽤
// template <class T> void f2(T &&x) {}
// int main() {
//   typedef int &lref;
//   typedef int &&rref;
//   int n = 0;
//   lref &r1 = n;  // r1 的类型是 int&
//   lref &&r2 = n; // r2 的类型是 int&
//   rref &r3 = n;  // r3 的类型是 int&
//   rref &&r4 = 1; // r4 的类型是 int&&
//   // 没有折叠->实例化为void f1(int& x)
//   f1<int>(n);
//   f1<int>(0); // 报错
//   // 折叠->实例化为void f1(int& x)
//   f1<int &>(n);
//   f1<int &>(0); // 报错
//   // 折叠->实例化为void f1(int& x)
//   f1<int &&>(n);
//   f1<int &&>(0); // 报错
//   // 折叠->实例化为void f1(const int& x)
//   f1<const int &>(n);
//   f1<const int &>(0);
//   // 折叠->实例化为void f1(const int& x)
//   f1<const int &&>(n);
//   f1<const int &&>(0);
//   // 没有折叠->实例化为void f2(int&& x)
//   f2<int>(n); // 报错
//   f2<int>(0);
//   // 折叠->实例化为void f2(int& x)
//   f2<int &>(n);
//   f2<int &>(0); // 报错
//   // 折叠->实例化为void f2(int&& x)
//   f2<int &&>(n); // 报错
//   f2<int &&>(0);
//   return 0;
// }

// template <class T> void Function(T &&t) {
//   int a = 0;
//   T x = a;
//   // x++;
//   cout << &a << endl;
//   cout << &x << endl << endl;
// }
// int main() {
//   // 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//   Function(10); // 右值
//   int a;
//   // a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
//   Function(a); // 左值
//   // std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//   Function(std::move(a)); // 右值
//   const int b = 8;
//   // a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const
//   // int& t) 所以Function内部会编译报错，x不能++
//   Function(b); // const 左值
//   // std::move(b)右值，推导出T为const int，模板实例化为void Function(const
//   // int&&t) 所以Function内部会编译报错，x不能++
//   Function(std::move(b)); // const 右值
//   return 0;
// }

// void Fun(int &x) { cout << "左值引⽤" << endl; }
// void Fun(const int &x) { cout << "const 左值引⽤" << endl; }
// void Fun(int &&x) { cout << "右值引⽤" << endl; }
// void Fun(const int &&x) { cout << "const 右值引⽤" << endl; }
// template <class T> void Function(T &&t) {
//   Fun(t);
//   // Fun(forward<T>(t)); forward要显示实例化，不然t左值 forward后还是左值
// }
// int main() {
//   // 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//   Function(10); // 右值
//   int a;
//   // a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
//   Function(a); // 左值
//   // std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//   Function(std::move(a)); // 右值
//   const int b = 8;
//   // a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const
//   // int& t)
//   Function(b); // const 左值
//                // std::move(b)右值，推导出T为const int，模板实例化为void
//                // Function(const int&& t)
//   Function(std::move(b)); // const 右值
//   return 0;
// }

// template <class... Args> void Print(Args &&...args) {
//   cout << sizeof...(args) << endl;
// }
// int main() {
//   double x = 2.2;
//   Print();                        // 参数包⾥有0个参数
//   Print(1);                       // 参数包⾥有1个参数
//   Print(1, string("xxxxx"));      // 参数包⾥有2个参数
//   Print(1.1, string("xxxxx"), x); // 参数包⾥有3个参数
//   return 0;
// }
// // 原理1：编译本质这⾥会结合引⽤折叠规则实例化出以下四个函数 void Print();
// void Print(int &&arg1);
// void Print(int &&arg1, string &&arg2);
// void Print(double &&arg1, string &&arg2, double &arg3);
// // 原理2：更本质去看没有可变参数模板，我们实现出这样的多个函数模板才能⽀持
// // 这⾥的功能，有了可变参数模板，我们进⼀步被解放，他是类型泛化基础
// // 上叠加数量变化，让我们泛型编程更灵活。
// void Print();
// template <class T1> void Print(T1 &&arg1);
// template <class T1, class T2> void Print(T1 &&arg1, T2 &&arg2);
// template <class T1, class T2, class T3>
// void Print(T1 &&arg1, T2 &&arg2, T3 &&arg3);
// // ...

// void ShowList() {
//   // 编译器时递归的终⽌条件，参数包是0个时，直接匹配这个函数
//   cout << endl;
// }
// template <class T, class... Args> void ShowList(T x, Args... args) {
//   cout << x << " ";
//   // args是N个参数的参数包
//   // 调⽤ShowList，参数包的第⼀个传给x，剩下N-1传给第⼆个参数包
//   ShowList(args...);
// }
// // 编译时递归推导解析参数
// template <class... Args> void Print(Args... args) { ShowList(args...); }
// int main() {
//   Print();
//   Print(1);
//   Print(1, string("xxxxx"));
//   Print(1, string("xxxxx"), 2.2);
//   return 0;
// }
// template <class T, class... Args>
//  void ShowList(T x, Args... args)
//{
//   cout << x << " ";
//   Print(args...);
//  }
//   Print(1, string("xxxxx"), 2.2);调⽤时
//   本质编译器将可变参数模板通过模式的包扩展，编译器推导的以下三个重载函数函数
//  void ShowList(double x)
//{
//   cout << x << " ";
//  ShowList();
// }
//
//  void ShowList(string x, double z)
//{
//  cout << x << " ";
//  ShowList(z);
// }
//
//  void ShowList(int x, string y, double z)
//{
//  cout << x << " ";
//  ShowList(y, z);
// }
//  void Print(int x, string y, double z)
//{
//  ShowList(x, y, z);
// }

// int main() {
//   auto add1 = [](int x, int y) { return x + y; };
//   cout << add1(5, 4);
//   return 0;
// }

// int main() {
//   // ⼀个简单的lambda表达式
//   auto add1 = [](int x, int y) -> int { return x + y; };
//   cout << add1(1, 2) << endl;
//   // 1、捕捉为空也不能省略
//   // 2、参数为空可以省略
//   // 3、返回值可以省略，可以通过返回对象⾃动推导
//   // 4、函数题不能省略
//   auto func1 = [] {
//     cout << "hello bit" << endl;
//     return 0;
//   };
//   func1();
//   int a = 0, b = 1;
//   auto swap1 = [](int &x, int &y) {
//     int tmp = x;
//     x = y;
//     y = tmp;
//   };
//   swap1(a, b);
//   cout << a << ":" << b << endl;
//   return 0;
// }

// int x = 0;
// // 捕捉列表必须为空，因为全局变量不⽤捕捉就可以⽤，没有可被捕捉的变量
// auto func1 = []() { x++; };

// int main() {
//   // 只能⽤当前lambda局部域和捕捉的对象和全局对象
//   int a = 0, b = 1, c = 2, d = 3;
//   auto func1 = [a, &b] {
//     // 值捕捉的变量不能修改，引⽤捕捉的变量可以修改
//     // a++;
//     b++;
//     int ret = a + b;
//     return ret;
//   };
//   cout << func1() << endl;
//   // 隐式值捕捉
//   // ⽤了哪些变量就捕捉哪些变量
//   auto func2 = [=] {
//     int ret = a + b + c;
//     return ret;
//   };
//   cout << func2() << endl;
//   // 隐式引⽤捕捉
//   // ⽤了哪些变量就捕捉哪些变量
//   auto func3 = [&] {
//     a++;
//     c++;
//     d++;
//   };
//   func3();
//   cout << a << " " << b << " " << c << " " << d << endl;
//   // 混合捕捉1
//   auto func4 = [&, a, b] {
//     // a++;
//     // b++;
//     c++;
//     d++;
//     return a + b + c + d;
//   };
//   func4();
//   cout << a << " " << b << " " << c << " " << d << endl;
//   // 混合捕捉1
//   auto func5 = [=, &a, &b] {
//     a++;
//     b++;
//     /*c++;
//     d++;*/
//     return a + b + c + d;
//   };
//   func5();
//   cout << a << " " << b << " " << c << " " << d << endl;
//   // 局部的静态和全局变量不能捕捉，也不需要捕捉
//   static int m = 0;
//   auto func6 = [] {
//     int ret = x + m;
//     return ret;
//   };
//   // 传值捕捉本质是⼀种拷⻉,并且被const修饰了
//   // mutable相当于去掉const属性，可以修改了
//   // 但是修改了不会影响外⾯被捕捉的值，因为是⼀种拷⻉
//   auto func7 = [=]() mutable {
//     a++;
//     b++;
//     c++;
//     d++;
//     return a + b + c + d;
//   };
//   cout << func7() << endl;
//   cout << a << " " << b << " " << c << " " << d << endl;
//   return 0;
// }

// struct Goods {
//   string _name;  // 名字
//   double _price; // 价格
//   int _evaluate; // 评价
//   // ...
//   Goods(const char *str, double price, int evaluate)
//       : _name(str), _price(price), _evaluate(evaluate) {}
// };

// struct ComparePriceLess {
//   bool operator()(const Goods &gl, const Goods &gr) {
//     return gl._price < gr._price;
//   }
// };
// struct ComparePriceGreater {
//   bool operator()(const Goods &gl, const Goods &gr) {
//     return gl._price > gr._price;
//   }
// };
// int main() {
//   vector<Goods> v = {
//       {"苹果", 2.1, 5}, {"⾹蕉", 3, 4}, {"橙⼦", 2.2, 3}, {"菠萝", 1.5, 4}};
//   // 类似这样的场景，我们实现仿函数对象或者函数指针⽀持商品中
//   // 不同项的⽐较，相对还是⽐较⿇烦的，那么这⾥lambda就很好⽤了
//   sort(v.begin(), v.end(), ComparePriceLess());
//   sort(v.begin(), v.end(), ComparePriceGreater());

//   sort(v.begin(), v.end(),
//        [](const Goods &g1, const Goods &g2) { return g1._price < g2._price;
//        });
//   sort(v.begin(), v.end(),
//        [](const Goods &g1, const Goods &g2) { return g1._price > g2._price;
//        });

//   sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2) {
//     return g1._evaluate < g2._evaluate;
//   });
//   sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2) {
//     return g1._evaluate > g2._evaluate;
//   });
//   return 0;
// }

// #include <functional>
// int f(int a, int b) { return a + b; }
// struct Functor {
// public:
//   int operator()(int a, int b) { return a + b; }
// };
// class Plus {
// public:
//   Plus(int n = 10) : _n(n) {}
//   static int plusi(int a, int b) { return a + b; }
//   double plusd(double a, double b) { return (a + b) * _n; }

// private:
//   int _n;
// };
// int main() {
//   // 包装各种可调⽤对象
//   function<int(int, int)> f1 = f;
//   function<int(int, int)> f2 = Functor();
//   function<int(int, int)> f3 = [](int a, int b) { return a + b; };
//   cout << f1(1, 1) << endl;
//   cout << f2(1, 1) << endl;
//   cout << f3(1, 1) << endl;
//   // 包装静态成员函数
//   // 成员函数要指定类域并且前⾯加&才能获取地址
//   function<int(int, int)> f4 = &Plus::plusi;
//   cout << f4(1, 1) << endl;
//   // 包装普通成员函数
//   //
//   普通成员函数还有⼀个隐含的this指针参数，所以绑定时传对象或者对象的指针过去都可以
//   function<double(Plus *, double, double)> f5 = &Plus::plusd;
//   Plus pd;
//   cout << f5(&pd, 1.1, 1.1) << endl;
//   function<double(Plus, double, double)> f6 = &Plus::plusd;
//   cout << f6(pd, 1.1, 1.1) << endl;
//   cout << f6(pd, 1.1, 1.1) << endl;
//   function<double(Plus &&, double, double)> f7 = &Plus::plusd;
//   cout << f7(move(pd), 1.1, 1.1) << endl;
//   cout << f7(Plus(), 1.1, 1.1) << endl;
//   return 0;
// }

// #include <functional>
// using placeholders::_1;
// using placeholders::_2;
// using placeholders::_3;
// int Sub(int a, int b) { return (a - b) * 10; }
// int SubX(int a, int b, int c) { return (a - b - c) * 10; }
// class Plus {
// public:
//   static int plusi(int a, int b) { return a + b; }
//   double plusd(double a, double b) { return a + b; }
// };
// int main() {
//   auto sub1 = bind(Sub, _1, _2);
//   cout << sub1(10, 5) << endl;
//   // bind 本质返回的⼀个仿函数对象
//   // 调整参数顺序（不常⽤）
//   // _1代表第⼀个实参
//   // _2代表第⼆个实参
//   // ...

//   auto sub2 = bind(Sub, _2, _1);
//   cout << sub2(10, 5) << endl;

//   // 调整参数个数 （常⽤）
//   auto sub3 = bind(Sub, 100, _1);
//   cout << sub3(5) << endl;
//   auto sub4 = bind(Sub, _1, 100);
//   cout << sub4(5) << endl;

//   // 分别绑死第123个参数
//   auto sub5 = bind(SubX, 100, _1, _2);
//   cout << sub5(5, 1) << endl;
//   auto sub6 = bind(SubX, _1, 100, _2);
//   cout << sub6(5, 1) << endl;
//   auto sub7 = bind(SubX, _1, _2, 100);
//   cout << sub7(5, 1) << endl;

//   // 成员函数对象进⾏绑死，就不需要每次都传递了
//   function<double(Plus &&, double, double)> f6 = &Plus::plusd;
//   Plus pd;
//   cout << f6(move(pd), 1.1, 1.1) << endl;
//   cout << f6(Plus(), 1.1, 1.1) << endl;

//   // bind⼀般⽤于，绑死⼀些固定参数
//   function<double(double, double)> f7 = bind(&Plus::plusd, Plus(), _1, _2);
//   /*
//   &Plus::plusd 表示要绑定的函数是 Plus 类中的成员函数 plusd
//   Plus()
//   这里是创建一个临时对象來調用成员函数，成员函数必须透过对象來呼叫，所以这是
//   this 的替代物 换句话说：这告诉 bind：当要呼叫 plusd 时，就用这个 Plus()
//   实例來呼叫
//   */
//   cout << f7(1.1, 1.1) << endl;
//   // 计算复利的lambda
//   auto func1 = [](double rate, double money, int year) -> double {
//     double ret = money;
//     for (int i = 0; i < year; i++) {
//       ret += ret * rate;
//     }
//     return ret - money;
//   };
//   //
//   绑死⼀些参数，实现出⽀持不同年华利率，不同⾦额和不同年份计算出复利的结算利息
//   function<double(double)> func3_1_5 = bind(func1, 0.015, _1, 3);
//   function<double(double)> func5_1_5 = bind(func1, 0.015, _1, 5);
//   function<double(double)> func10_2_5 = bind(func1, 0.025, _1, 10);
//   function<double(double)> func20_3_5 = bind(func1, 0.035, _1, 30);
//   cout << func3_1_5(1000000) << endl;
//   cout << func5_1_5(1000000) << endl;
//   cout << func10_2_5(1000000) << endl;
//   cout << func20_3_5(1000000) << endl;
//   return 0;
// }
