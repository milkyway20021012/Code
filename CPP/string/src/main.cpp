#include "../include/string.h"
#include <iostream>
#include <utility>
using namespace std;

// void test01()
// {
//     // bit::string s1("Hello Bit");
//     // cout << s1.c_str() << endl;
//     // bit::string s2;
//     // cout << s2.c_str() << endl;
//     // cout << s1.size() << endl;
//     // for (size_t i = 0; i < s1.size(); ++i)
//     // {
//     //     cout << s1[i];
//     // }
//     // cout << endl;
//     // bit::string::iterator it = s1.begin();
//     // while (it != s1.end())
//     // {
//     //     cout << *it;
//     //     it++;
//     // }
//     // cout << endl;
//     // for (auto ch : s1)
//     // {
//     //     cout << ch;
//     // }
//     // cout << endl;
//     // const bit::string s1("Hello Bit");
//     // bit::string::const_iterator it = s1.begin();
//     // while (it != s1.end())
//     // {
//     //     // *it += 1; 不允許修改
//     //     cout << *it;
//     //     it++;
//     // }
//     // cout << endl;
//     bit::string s1("Hello World");
//     // s1.push_back(' ');
//     // s1.push_back('!');
//     // for (auto ch : s1)
//     // {
//     //     cout << ch;
//     // }
//     // cout << endl;
//     // s1.append("\nHello");
//     // for (auto ch : s1)
//     // {
//     //     cout << ch;
//     // }
//     // cout << endl;
//     // s1 += '!';
//     // s1 += "\n Hello";
//     // for (auto ch : s1)
//     // {
//     //     cout << ch;
//     // }
//     // cout << endl;
//     // s1.insert(0, 3, '#');
//     // for (auto ch : s1)
//     // {
//     //     cout << ch;
//     // }
//     // cout << endl;
//     // s1.insert(0, "My World");
//     // for (auto ch : s1)
//     // {
//     //     cout << ch;
//     // }
//     // cout << endl;
//     s1.erase();
//     for (auto ch : s1)
//     {
//         cout << ch;
//     }
//     cout << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// 移动搞砸测试

// int main() {
//   bit::string s1("xxxxx");
//   // 拷⻉构造
//   bit::string s2 = s1;
//   // 构造+移动构造，优化后直接构造
//   bit::string s3 = bit::string("yyyyy");
//   // 移动构造
//   bit::string s4 = move(s1);
//   cout << "******************************" << endl;
//   return 0;
// }

// namespace bit {
// string addStrings(string num1, string num2) {
//   string str;
//   int end1 = num1.size() - 1, end2 = num2.size() - 1;
//   int next = 0;
//   while (end1 >= 0 || end2 >= 0) {
//     int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//     int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//     int ret = val1 + val2 + next;
//     next = ret / 10;
//     ret = ret % 10;
//     str += ('0' + ret);
//   }
//   if (next == 1)
//     str += '1';
//   reverse(str.begin(), str.end());
//   cout << "******************************" << endl;
//   return str;
// }
// } // namespace bit
// // 场景1
// int main() {
//   bit::string ret = bit::addStrings("11111", "2222");
//   cout << ret.c_str() << endl;
//   return 0;
// }
// // 场景2
// // int main() {
// //   bit::string ret;
// //   ret = bit::addStrings("11111", "2222");
// //   cout << ret.c_str() << endl;
// //   return 0;
// // }