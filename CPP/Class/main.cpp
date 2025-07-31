#include <iostream>
using namespace std;
// class A {
// public:
//   void Print() { cout << "A::Print()" << endl; }
// private:
//   int _a;
// };
// int main() {
//   A *p = nullptr;
//   p->Print();
//   return 0;
// }

// class A {
// public:
//   void Print() {
//     cout << "A::Print()" << endl;
//     cout << _a << endl;
//   }
// private:
//   int _a;
// };
// int main() {
//   A *p = nullptr;
//   p->Print();
//   return 0;
// }

class Person {
public:
  // Person() { _a = 10; }
  Person(int a = 10) : _a(a) { cout << _a << endl; }

private:
  int _a;
};

int main() {
  Person p;
  return 0;
}