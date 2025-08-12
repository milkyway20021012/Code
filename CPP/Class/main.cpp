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

// class Person {
// public:
//   // Person() { _a = 10; }
//   Person(int a = 10) : _a(a) { cout << _a << endl; }

// private:
//   int _a;
// };

// int main() {
//   Person p;
//   return 0;
// }

struct BTNode {
  BTNode *_left;
  BTNode *_right;
  char _data;
};
// 中序遍历
void InOrder(BTNode *_root) {
  if (_root == nullptr)
    return;
  InOrder(_root->_left);
  cout << _root->_data << " ";
  InOrder(_root->_right);
}
BTNode *CreateTree(string &str, size_t &i) {
  if (str[i] == '#')
    return nullptr;
  // 前序遍历建树
  auto _root = new BTNode;
  // 前序 根-左-右
  _root->_data = str[i++];
  _root->_left = CreateTree(str, i);
  _root->_right = CreateTree(str, i);
  return _root;
}
int main() {
  string str{"abc##de#g##f###"};
  size_t i = 0;
  BTNode *root = CreateTree(str, i);
  InOrder(root);
  cout << endl;
}
// 64 位输出请用 printf("%lld")