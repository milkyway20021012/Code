#include <iostream>
#include <memory>
using namespace std;

// double Divide(int a, int b) {
//   // 当b == 0时抛出异常
//   if (b == 0) {
//     throw "Divide by zero condition!";
//   } else {
//     return (double)a / (double)b;
//   }
// }
// void Func() {
//   // 如果array2
//   new的时候抛异常呢，就还需要套⼀层捕获释放逻辑，这⾥更好解决⽅案是智能指针，否则代码太杂了
//   int *array1 = new int[10];
//   int *array2 = new int[10]; // 抛异常呢
//   try {
//     int len, time;
//     cin >> len >> time;
//     cout << Divide(len, time) << endl;
//   } catch (...) {
//     // 捕获到Divide的异常要释放 否则会内存泄漏
//     cout << "delete []" << array1 << endl;
//     cout << "delete []" << array2 << endl;
//     delete[] array1;
//     delete[] array2;
//     throw; // 异常重新抛出，捕获到什么抛出什么
//   }
//   // ...
//   cout << "delete []" << array1 << endl;
//   delete[] array1;
//   cout << "delete []" << array2 << endl;
//   delete[] array2;
// }
// int main() {
//   try {
//     Func();
//   } catch (const char *errmsg) {
//     cout << errmsg << endl;
//   } catch (const exception &e) {
//     cout << e.what() << endl;
//   } catch (...) {
//     cout << "未知异常" << endl;
//   }
//   return 0;
// }

// template <class T> class SmartPtr {
// public:
//   SmartPtr(T *ptr) : _ptr(ptr) {}
//   ~SmartPtr() {
//     cout << "~SmartPointer 析构调用" << endl;
//     delete[] _ptr;
//   }
//   T &operator*() { return *_ptr; }
//   T *operator->() { return _ptr; }
//   T &operator[](size_t i) { return _ptr[i]; }
// private:
//   T *_ptr;
// };

// double Divide(int a, int b) {
//   // 当b == 0时抛出异常
//   if (b == 0) {
//     throw "Divide by zero condition!";
//   } else {
//     return (double)a / (double)b;
//   }
// }
// void Func() {
//   // 这⾥使⽤RAII的智能指针类管理new出来的数组以后，程序简单多了
//   SmartPtr<int> sp1 = new int[10];
//   SmartPtr<int> sp2 = new int[10];
//   for (size_t i = 0; i < 10; i++) {
//     sp1[i] = sp2[i] = i;
//   }
//   int len, time;
//   cin >> len >> time;
//   cout << Divide(len, time) << endl;
// }
// int main() {
//   try {
//     Func();
//   } catch (const char *errmsg) {
//     cout << errmsg << endl;
//   } catch (const exception &e) {
//     cout << e.what() << endl;
//   } catch (...) {
//     cout << "未知异常" << endl;
//   }
//   return 0;
// }

// struct Date {
//   int _year;
//   int _month;
//   int _day;
//   Date(int year = 1, int month = 1, int day = 1)
//       : _year(year), _month(month), _day(day) {}
//   ~Date() { cout << "~Date()" << endl; }
// };

// // int main() {
// //   auto_ptr<Date> ap1(new Date);
// //   // 拷⻉时，管理权限转移，被拷⻉对象ap1悬空
// //   // auto_ptr<Date> ap2(ap1);
// //   // 空指针访问，ap1对象已经悬空
// //   // ap1->_year++;
// //   unique_ptr<Date> up1(new Date);
// //   // unique_ptr<Date> up2(up1); // 不支持拷贝
// //   // unique_ptr<Date> up3(move(up1)); // 支持移动，但移动后可能导致悬空 =>
// //   移动相当于把 up1 的资源转给 up3 管理 shared_ptr<Date> sp1(new Date);
// //   shared_ptr<Date> sp2(sp1); // 支持拷贝
// //   shared_ptr<Date> sp3(sp1);
// //   cout << sp1.use_count() << endl; // 3
// //   sp1->_year++;
// //   cout << sp1->_year << endl;
// //   cout << sp2->_year << endl;
// //   cout << sp3->_year << endl;
// //   // ⽀持移动，但是移动后sp1也悬空，所以使⽤移动要谨慎
// //   shared_ptr<Date> sp4(move(sp1));
// //   return 0;
// // }

// template <class T> void DeleteArrayFunc(T *ptr) { delete[] ptr; }

// template <class T> class DeleteArray {
// public:
//   void operator()(T *ptr) { delete[] ptr; }
// };
// class Fclose {
// public:
//   void operator()(FILE *ptr) {
//     cout << "fclose:" << ptr << endl;
//     fclose(ptr);
//   }
// };
// int main() {
//   // 这样实现程序会崩溃
//   // unique_ptr<Date> up1(new Date[10]);
//   // shared_ptr<Date> sp1(new Date[10]);

//   /* 解决⽅案1
//   因为new[]经常使⽤，所以unique_ptr和shared_ptr
//   实现了⼀个特化版本，这个特化版本析构时⽤的delete[]
//   unique_ptr<Date[]> up1(new Date[5]);
//   shared_ptr<Date[]> sp1(new Date[5]);
//   - C++17  前没有对shared_pt做 []特化
//   */

//   /*解决⽅案2
//   仿函数对象做删除器
//   unique_ptr<Date, DeleteArray<Date>> up2(new Date[5], DeleteArray<Date>());
//   unique_ptr和shared_ptr⽀持删除器的⽅式有所不同
//   {unique_ptr} 是在「类模板参数⽀持」的，{shared_ptr}是「构造函数参数⽀持」的
//   这⾥没有使⽤相同的⽅式还是挺糟糕的
//   使⽤仿函数unique_ptr可以不在构造函数传递，因为仿函数类型构造的对象直接就可以调⽤
//   但是下⾯的函数指针和lambda的类型不可以
//   */

//   unique_ptr<Date, DeleteArray<Date>> up2(new Date[5], DeleteArray<Date>());
//   shared_ptr<Date> sp2(new Date[5],
//                        DeleteArray<Date>()); // DeleteArray<Date> ()
//                        为匿名对象
//   // 函数指针做删除器
//   unique_ptr<Date, void (*)(Date *)> up3(new Date[5], DeleteArrayFunc<Date>);
//   shared_ptr<Date> sp3(new Date[5], DeleteArrayFunc<Date>);
//   // lambda表达式做删除器
//   auto delArrOBJ = [](Date *ptr) { delete[] ptr; };
//   unique_ptr<Date, decltype(delArrOBJ)> up4(new Date[5], delArrOBJ);
//   shared_ptr<Date> sp4(new Date[5], delArrOBJ);
//   // 实现其他资源管理的删除器
//   shared_ptr<FILE> sp5(fopen("Test.cpp", "r"), Fclose());
//   shared_ptr<FILE> sp6(fopen("Test.cpp", "r"), [](FILE *ptr) {
//     cout << "fclose:" << ptr << endl;
//     fclose(ptr);
//   });
//   return 0;
// }

namespace bit {
template <class T> class auto_ptr {
public:
  auto_ptr(T *ptr) : _ptr(ptr) {}

  auto_ptr(auto_ptr<T> &ptr) {
    _ptr = ptr._ptr;
    ptr._ptr = nullptr;
  }

  auto_ptr &operator=(auto_ptr<T> &ptr) {
    if (this != ptr) {
      if (_ptr) {
        delete _ptr; // 先释放 不然会有内存泄漏的问题
      }
      _ptr = ptr._ptr;
      ptr._ptr = nullptr;
    }
    return *this;
  }

  ~auto_ptr() {
    if (_ptr) {
      cout << "~auto_ptr()" << endl;
      delete _ptr;
    }
  }
  T &operator*() { return *_ptr; }

  T *operator->() { return _ptr; }

private:
  T *_ptr;
};

template <class T> class unique_ptr {
public:
  explicit unique_ptr(T *up) : _ptr(up) {}
  unique_ptr(T &&up) : _ptr(up) { // 允许移动
    up.ptr = nullptr;
  }

  ~unique_ptr() {
    if (_ptr) {
      cout << "~unique_ptr()" << endl;
      delete _ptr;
    }
  }
  T &operator*() { return *_ptr; }
  T *operator->() { return _ptr; }
  unique_ptr(const unique_ptr<T> &up) =
      delete; // 不允许拷贝(连默认拷贝都不能生成)
  unique_ptr<T> &operator=(const unique_ptr<T> &up) = delete;
  unique_ptr<T> &operator=(const unique_ptr<T> &&up) {
    if (_ptr)
      delete _ptr;
    _ptr = up._ptr;
    up._ptr = nullptr;
  }

private:
  T *_ptr;
};
template <class T> class shared_ptr {
  // shared_ptr的实现 --- 指针与引用计数
public:
  explicit shared_ptr(T *sp) : _ptr(sp), p_count(new int(1)) {}
  ~shared_ptr() { release(); }
  shared_ptr(const shared_ptr<T> &sp) : _ptr(sp._ptr), p_count(sp.p_count) {
    ++(*p_count);
  }
  template <class D>
  shared_ptr(T *ptr, D del) : _ptr(ptr), p_count(new int(1)), _del(del) {}
  /*
  如何推出 D
  步驟一：看你傳進來的是什麼 你傳進來的是 del，它是一個 lambda。
  lambda 在 C++ 裡有一個「隱藏的型別」（closure
  type），這個型別是編譯器自動產生的。 步驟二：D 就是 del 的型別 編譯器看到 D
  del，就會把 del 的型別當作 D。
  這個型別可以是lambda、函式指標、函式物件，都可以。
  步驟三：D 會自動推導，不用你寫 你不用寫
  shared_ptr<int, decltype(del)>，只要寫 shared_ptr<int>，編譯器會自動幫你推導 D
   */
  void release() {
    if (--(*p_count) == 0) {
      _del(_ptr);
      delete p_count;
      _ptr = nullptr;
      p_count = nullptr;
    }
  }
  shared_ptr<T> &operator=(shared_ptr<T> &sp) {
    if (_ptr != sp._ptr) {
      release();
      _ptr = sp._ptr;
      p_count = sp.p_count;
      _del = sp._del;
      ++(*p_count);
    }
    return *this;
  }
  T *get() const { return _ptr; }
  int use_count() const { return *p_count; }
  T &operator*() { return *_ptr; }
  T *operator->() { return _ptr; }

private:
  T *_ptr;
  int *p_count; // 计数
  function<void(T *)> _del = [](T *ptr) { delete ptr; };
};
// 需要注意的是我们这⾥实现的shared_ptr和weak_ptr都是以最简洁的⽅式实现的，
// 只能满⾜基本的功能，这⾥的weak_ptr lock等功能是⽆法实现的，想要实现就要
// 把shared_ptr和weak_ptr⼀起改了，把引⽤计数拿出来放到⼀个单独类型，shared_ptr
// 和weak_ptr都要存储指向这个类的对象才能实现，有兴趣可以去翻翻源代码
template <class T> class weak_ptr {
public:
  weak_ptr(const shared_ptr<T> &sp) : _ptr(sp.get()) {}
  weak_ptr<T> &operator=(const shared_ptr<T> &sp) {
    _ptr = sp.get();
    return *this;
  }

private:
  T *_ptr = nullptr;
};
} // namespace bit

struct ListNode {
  int _data;
  std::shared_ptr<ListNode> _next;
  std::shared_ptr<ListNode> _prev;
  // 这⾥改成weak_ptr，当n1->_next = n2;绑定shared_ptr时
  // 不增加n2的引⽤计数，不参与资源释放的管理，就不会形成循环引⽤了
  /*std::weak_ptr<ListNode> _next;
  std::weak_ptr<ListNode> _prev;*/
  ~ListNode() { cout << "~ListNode()" << endl; }
};
int main() {
  // 循环引⽤ -- 内存泄露
  std::shared_ptr<ListNode> n1(new ListNode);
  std::shared_ptr<ListNode> n2(new ListNode);
  cout << n1.use_count() << endl;
  cout << n2.use_count() << endl;
  n1->_next = n2;
  n2->_prev = n1;
  cout << n1.use_count() << endl;
  cout << n2.use_count() << endl;
  // weak_ptr不⽀持管理资源，不⽀持RAII
  // weak_ptr是专⻔绑定shared_ptr，不增加他的引⽤计数，作为⼀些场景的辅助管理
  // std::weak_ptr<ListNode> wp(new ListNode);
  return 0;
}