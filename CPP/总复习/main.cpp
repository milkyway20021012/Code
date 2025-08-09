#include <iostream>
using namespace std;
// 开启Augment自动补齐 -> Augment -> Settings -> Completions

// class A {
// public:
//   A(int _a = 10) {}
//   void Print() { cout << _a << endl; }
// private:
//   int _a;
// };
// int main() {
//   A a;
//   a.Print();
//   return 0;
// }
// class Time {
// public:
//   Time(int hour) : _hour(hour) {}
//   int Get_Hour() { return _hour; }
// private:
//   int _hour;
// };
// class Date {
// public:
//   Date(int &x, int year = 2025, int month = 7, int day = 31)
//       : _year(year), _month(month), _day(day), _n(10), _t(7), ret(x) {}
//   void Print() {
//     cout << _year << "-" << _month << "-" << _day << endl;
//     cout << _n << " " << _t.Get_Hour() << " " << ret << endl;
//   }
// private:
//   int _year;
//   int _month;
//   int _day;
//   const int _n; // const 成员变量
//   Time _t;      // 自定义类型
//   int &ret;     // 引用
// };
// int main() {
//   int i = 0;
//   Date d1(i);
//   d1.Print();
//   const int b;
//   return 0;
// }

// class Time {
// public:
//   Time(int hour) : _hour(hour) { cout << "Time()" << endl; }
// private:
//   int _hour;
// };
// class Date {
// public:
//   Date() : _month(2) { cout << "Date()" << endl; }
//   void Print() const { cout << _year << "-" << _month << "-" << _day << endl;
//   }
// private:
//   // 注意这⾥不是初始化，这⾥给的是缺省值，这个缺省值是给初始化列表的
//   // 如果初始化列表没有显⽰初始化，默认就会⽤这个缺省值初始化
//   int _year = 1;
//   int _month = 1;
//   int _day;
//   Time _t = 1;
//   const int _n = 1;
//   int *_ptr = (int *)malloc(12);
// };
// int main() {
//   Date d1;
//   d1.Print();
//   return 0;
// }

// class A {
// public:
//   A(int a) : _a1(a), _a2(_a1) {}
//   void Print() { cout << _a1 << " " << _a2 << endl; }
// private:
//   int _a2 = 2;
//   int _a1 = 2;
// };
// int main() {
//   A aa(1);
//   aa.Print();
// }

// class A {
// public:
//   // 构造函数explicit就不再⽀持隐式类型转换
//   // explicit A(int a1)
//   A(int a1) : _a1(a1) {}
//   // explicit A(int a1, int a2)
//   A(int a1, int a2) : _a1(a1), _a2(a2) {}
//   void Print() { cout << _a1 << " " << _a2 << endl; }
//   int Get() const { return _a1 + _a2; }
// private:
//   int _a1 = 1;
//   int _a2 = 2;
// };
// class B {
// public:
//   B(const A &a) : _b(a.Get()) {}
// private:
//   int _b = 0;
// };
// int main() {
//   // 1构造⼀个A的临时对象，再⽤这个临时对象拷⻉构造aa3
//   // 编译器遇到连续构造+拷⻉构造->优化为直接构造
//   A aa1 = 1;
//   aa1.Print();
//   const A &aa2 = 1;
//   // C++11之后才⽀持多参数转化
//   A aa3 = {2, 2};
//   // aa3隐式类型转换为b对象
//   // 原理跟上⾯类似
//   B b = aa3;
//   const B &rb = aa3;
//   return 0;
// }

// class A {
// public:
//   static int Get_Value() { return _a; }
// private:
//   static int _a;
//   int _b;
// };
// int A::_a = 10;
// int main() {
//   A a;
//   cout << a.Get_Value() << endl;
//   return 0;
// }

// 实现一个类，计算创建了多少对象
// class A {
// public:
//   A() { Count_Add(); }
//   A(int a) : _a(a) { Count_Add(); }
//   static void Count_Add() { ++_count; }
//   static int Get_Count() { return _count; }
// private:
//   static int _count;
//   int _a;
// };
// int A::_count = 0;
// int main() {
//   A a;
//   A b = 1; // 被优化了
//   cout << a.Get_Count() << endl;
//   return 0;
// }

// class A {
// public:
//   A() { ++_scount; }
//   A(const A &t) { ++_scount; }
//   ~A() { --_scount; }
//   static int GetACount() { return _scount; }
// private:
//   // 类⾥⾯声明
//   static int _scount;
// };
// // 类外⾯初始化
// int A::_scount = 0;
// int main() {
//   cout << A::GetACount() << endl;
//   A a1, a2;
//   A a3(a1);
//   cout << A::GetACount() << endl;
//   cout << a1.GetACount() << endl;
//   // 编译报错：error C2248: “A::_scount”: ⽆法访问 private
//   成员(在“A”类中声明)
//   // cout << A::_scount << endl;
//   return 0;
// }

// class A {
// private:
//   static int _k;
//   int _h = 1;
// public:
//   class B // B默认就是A的友元
//   {
//   public:
//     void foo(const A &a) {
//       cout << _k << endl;   // OK
//       cout << A::_h << endl; // OK
//     }
//     int _b1;
//   };
// };
// int A::_k = 1;
// int main() {
//   cout << sizeof(A) << endl;
//   A::B b;
//   A aa;
//   b.foo(aa);
//   return 0;
// }

// class A {
// public:
//   A(int a = 0) : _a(a) { cout << "A(int a)" << endl; }
//   ~A() { cout << "~A()" << endl; }
// private:
//   int _a;
// };
// class Solution {
// public:
//   int Sum_Solution(int n) {
//     //...
//     return n;
//   }
// };
// int main() {
//   A aa1;
//   // 不能这么定义对象，因为编译器⽆法识别下⾯是⼀个函数声明，还是对象定义
//   // A aa1();
//   // 但是我们可以这么定义匿名对象，匿名对象的特点不⽤取名字，
//   // 但是他的⽣命周期只有这⼀⾏，我们可以看到下⼀⾏他就会⾃动调⽤析构函数
//   A();
//   A(1);
//   A aa2(2);
//   //
//   匿名对象在这样场景下就很好⽤，当然还有⼀些其他使⽤场景，这个我们以后遇到了再说
//   Solution().Sum_Solution(10);
//   return 0;
// }

// class Person {
// private:
//   string _Name;
//   int _Age;
//   string _PhoneNumber;
//   // ....
// };
// class Teacher : public Person {
// private:
//   int _ID;
//   string _Course;
//   // ...
// };
// class Student : public Person {
// private:
//   int _StuID;
//   // ...
// };
// int main() {
//   Person p;
//   Teacher t;
//   Student s;
//   return 0;
// }

// class Person {
// protected:
//   string _name; // 姓名
//   string _sex;  // 性别
//   int _age;     // 年龄
// };
// class Student : public Person {
// public:
//   int _No; // 学号
// };
// int main() {
//   Student sobj;
//   // 1.派⽣类对象可以赋值给基类的指针/引⽤
//   Person *pp = &sobj;
//   Person &rp = sobj;
//   // ⽣类对象可以赋值给基类的对象是通过调⽤后⾯会讲解的基类的拷⻉构造完成的
//   Person pobj = sobj;
//   // 2.基类对象不能赋值给派⽣类对象，这⾥会编译报错
//   sobj = pobj;
//   return 0;
// }

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是⾮常容易混淆
// class Person {
// protected:
//   string _name = "⼩李⼦"; // 姓名
//   int _num = 111;          // ⾝份证号
// };
// class Student : public Person {
// public:
//   void Print() {
//     cout << " 姓名:" << _name << endl;
//     cout << " ⾝份证号:" << Person::_num << endl;
//     cout << " 学号:" << _num << endl;
//   }
// protected:
//   int _num = 999; // 学号
// };
// int main() {
//   Student s1;
//   s1.Print();
//   return 0;
// };

// class A {
// public:
//   void fun() { cout << "func()" << endl; }
// };
// class B : public A {
// public:
//   // void fun(int i) { cout << "func(int i)" << i << endl; }
// };
// int main() {
//   B b;
//   // b.fun(10);
//   b.fun();
//   return 0;
// }

// class Person {
// public:
//   Person(const char *name = "peter") : _name(name) {
//     cout << "Person()" << endl;
//   }
//   Person(const Person &p) : _name(p._name) {
//     cout << "Person(const Person& p)" << endl;
//   }
//   Person &operator=(const Person &p) {
//     cout << "Person operator=(const Person& p)" << endl;
//     if (this != &p)
//       _name = p._name;
//     return *this;
//   }
//   ~Person() { cout << "~Person()" << endl; }
// protected:
//   string _name; // 姓名
// };
// class Student : public Person {
// public:
//   Student(const char *name, int num) : Person(name), _num(num) {
//     cout << "Student()" << endl;
//   }
//   Student(const Student &s) : Person(s), _num(s._num) {
//     cout << "Student(const Student& s)" << endl;
//   }
//   Student &operator=(const Student &s) {
//     cout << "Student& operator= (const Student& s)" << endl;
//     if (this != &s) {
//       // 构成隐藏，所以需要显⽰调⽤
//       Person::operator=(s);
//       _num = s._num;
//     }
//     return *this;
//   }
//   ~Student() { cout << "~Student()" << endl; }
// protected:
//   int _num; // 学号
// };
// int main() {
//   Student s1("jack", 18);
//   Student s2(s1);
//   Student s3("rose", 17);
//   s1 = s3;
//   return 0;
// }

// class Base final {
//   Base() {}
// private:
//   int _a = 10;
// };
// class Derived : public Base {
// private:
//   int _b = 20;
// };
// int main() {
//   Derived d;
//   return 0;
// }

// class Derived;
// class Base {
//   friend void display(const Base &b, const Derived &d);
// public:
// private:
//   int _a = 10;
// };
// class Derived {
//   // friend void display(const Base &b, const Derived &d);
// private:
//   int _b = 20;
// };
// void display(const Base &b, const Derived &d) {
//   cout << b._a << endl; // 可以访问Base 的私有
//   cout << d._b << endl; // 不能访问
// }

// class Person {
// public:
//   string _name;
//   static int _count;
// };
// int Person::_count = 0;
// class Student : public Person {
// protected:
//   int _stuNum;
// };
// int main() {
//   Person p;
//   Student s;
//   // 这⾥的运⾏结果可以看到⾮静态成员_name的地址是不⼀样的
//   // 说明派⽣类继承下来了，⽗派⽣类对象各有⼀份
//   cout << &p._name << endl;
//   cout << &s._name << endl;
//   // 这⾥的运⾏结果可以看到静态成员_count的地址是⼀样的
//   // 说明派⽣类和基类共⽤同⼀份静态成员
//   cout << &p._count << endl;
//   cout << &s._count << endl;
//   // 公有的情况下，⽗派⽣类指定类域都可以访问静态成员
//   cout << Person::_count << endl;
//   cout << Student::_count << endl;
//   return 0;
// }

// class Person {
//   public : string _name; // 姓名
// };
// class Student : public Person {
//   protected : int _num; // 学号
// };
// class Teacher : public Person {
//   protected : int _id; // 职⼯编号
// };
// class Assistant : public Student, public Teacher {
//   protected : string _majorCourse; // 主修课程
// };
// int main() {
//   // 编译报错：error C2385: 对“_name”的访问不明确
//   Assistant a;
//   a._name = "peter";
//   //
//   需要显⽰指定访问哪个基类的成员可以解决⼆义性问题，但是数据冗余问题⽆法解决
//   a.Student::_name = "xxx";
//   a.Teacher::_name = "yyy";
//   return 0;
// }
// class Person {
// public:
//   string _name; // 姓名
//   /*int _tel;
//   int _age;
//   string _gender;
//   string _address;*/
//   // ...
// };
// // 使⽤虚继承Person类
// class Student : virtual public Person {
// protected:
//   int _num; // 学号
// };
// // 使⽤虚继承Person类
// class Teacher : virtual public Person {
// protected:
//   int _id; // 职⼯编号
// };
// // 教授助理
// class Assistant : public Student, public Teacher {
// protected:
//   string _majorCourse; // 主修课程
// };
// int main() {
//   // 使⽤虚继承，可以解决数据冗余和⼆义性
//   Assistant a;
//   a._name = "peter";
//   return 0;
// }

// class Base {
// protected:
//   int state = 0;
// };
// class Derived : public Base {
// public:
//   void reset() {
//     state = -999; // 直接改父类成员
//     cout << Base::state;
//   }
// };
// int main() {
//   Derived d;
//   d.reset();
//   return 0;
// }
// class StateHolder {
// private:
//   int state = 0;
// public:
//   void reset() { state = 0; }
// }
// class Derived {
// private:
//   StateHolder holder;
// public:
//   void reset() {
//     holder.reset(); // 间接操作
//   }
// };
// class Car {
// public:
//   virtual void Drive() = 0;
// };
// class Benz : public Car {
// public:
//   virtual void Drive() { cout << "Benz-舒适" << endl; }
// };
// class BMW : public Car {
// public:
//   virtual void Drive() { cout << "BMW-操控" << endl; }
// };
// int main() {
//   // 编译报错：error C2259: “Car”: ⽆法实例化抽象类
//   Car car;
//   Car *pBenz = new Benz;
//   pBenz->Drive();
//   Car *pBMW = new BMW;
//   pBMW->Drive();
//   return 0;
// }

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int n1 = 0, n2 = 0;
  while (n1 < nums1.size() && n2 < nums2.size()) {
    if (nums1[n1] != 0 && nums1[n1] <= nums2[n2])
      ++n1;
    if (nums1[n1] == 0) {
      nums1[n1] = nums2[n2++];
    } else {
      ++n1;
      nums1[n1] = nums1[n1 - 1];
      nums1[n1 - 1] = nums2[n2++];
    }
  }
  if (m == 0) {
    for (int i = 0; i < nums1.size(); ++i) {
      nums1[i] = nums2[i];
    }
  }
}

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  merge(nums1, 3, nums2, 3);
  for (int i = 0; i < nums1.size(); ++i) {
    cout << nums1[i] << " ";
  }
  return 0;
}