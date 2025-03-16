#include <iostream>
using namespace std;

// class Date{
//     // 第一种构造函数：无参构造函数
//   public:
//     Date(){
//       cout << "我是无参的构造函数" << endl;
//       _year = 1;
//       _month = 1;
//       _day = 1;
//     }
//     // 带参的构造函数（这个不是默认构造）
//     Date(int year, int month, int day){
//       cout <c< "我是带参的构造函数" << endl;
//       _year = year;
//       _month = month;
//       _day = day;
//     }
//     // 第二种构造函数：全缺省构造函数
//     // Date(int year = 1, int month = 1, int day = 1){
//     //   _year = year;
//     //   _month = month;
//     //   _day = day;
//     // }
//   private:
//     int _year;
//     int _month;
//     int _day;
//   };

// class Stack{
// public:
//   Stack(int n = 4){
//     cout << "调用 Stack()" << endl;
//     _a = (int*)malloc(sizeof(int)*n);
//     if(_a == NULL){
//       perror("malloc fail");
//       exit(-1);
//     }
//     _capacity = n;
//     _size = 0;
//   }
// private:
//   int* _a;
//   int _capacity;
//   int _size;
// };

// class Queue{
//   // ...
// private:
//   Stack pushst;
//   Stack popst;
// };
// int main(){
//     // Date d1;
//     // Queue q1;
//     return 0;
// }
// 拷贝构造函数
// class Date
// {
// public:
//     Date(int year = 2025, int month = 1, int day = 1) : _year(year), _month(month), _day(day)
//     {
//     }
//     // 拷贝构造函数
//     // 如果写的是 Date(Date d) -->  编译报错 ： error C2652: “Date”: 非法的复制构造函数: 第一个参数不应是“Date”
//     Date(Date &d)
//     {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }
//     // 也可以使用指针来实现拷贝(但此时就只是普通的构造函数而不是拷贝构造函数)
//     Date(Date *d)
//     {
//         _year = d->_year;
//         _month = d->_month;
//         _day = d->_day;
//     }
//     void Print()
//     {
//         cout << _year << "年" << _month << "月" << _day << "日" << endl;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;
// };
// void Func1(Date d)
// {
//     cout << &d << endl;
//     d.Print();
// }
// // Date &Func2()
// // {
// //     Date tmp;
// //     tmp.Print();
// //     // 这样可能会导致野引用，因为tmp 是一个局部变量
// //     return tmp;
// // }
// class Stack
// {
// public:
//     Stack(int n = 4)
//     {
//         cout << "调用 Stack()" << endl;
//         _a = (int *)malloc(sizeof(int) * n);
//         if (_a == NULL)
//         {
//             perror("malloc fail");
//             exit(-1);
//         }
//         _capacity = n;
//         _top = 0;
//     }
//     Stack(const Stack &st)
//     {
//         _a = (int *)malloc(sizeof(int) * st._top);
//         if (nullptr == _a)
//         {
//             perror("malloc fail");
//             exit(-1);
//         }
//         memcpy(_a, st._a, sizeof(int) * st._top);
//         _capacity = st._capacity;
//         _top = st._top;
//     }
// private:
//     int *_a;
//     int _capacity;
//     int _top;
// }
// int main()
// {
//     Date d1(2025, 3, 14);
//     Func1(d1);
//     /*
//     C++规定定义对类型对象进行拷贝行为必须调用拷贝构造，所以这里传值传参要调用拷贝
//     所以这里的d1传值传参给d要调用拷贝构造完成拷贝，传引用传参可以省去这里的拷贝
//     */
//     Date d2(&d1); // 这里传入的是 d1 的地址 不是引用！
//     d2.Print();
//     d1.Print();
//     Date d3(d1); // 这样写才是调用拷贝构造函数
//     d3.Print();
//     return 0;
// }
