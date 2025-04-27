#include <iostream>
#include "../include/string.h"
using namespace std;

void test01()
{
    // bit::string s1("Hello Bit");
    // cout << s1.c_str() << endl;
    // bit::string s2;
    // cout << s2.c_str() << endl;
    // cout << s1.size() << endl;
    // for (size_t i = 0; i < s1.size(); ++i)
    // {
    //     cout << s1[i];
    // }
    // cout << endl;
    // bit::string::iterator it = s1.begin();
    // while (it != s1.end())
    // {
    //     cout << *it;
    //     it++;
    // }
    // cout << endl;
    // for (auto ch : s1)
    // {
    //     cout << ch;
    // }
    // cout << endl;
    // const bit::string s1("Hello Bit");
    // bit::string::const_iterator it = s1.begin();
    // while (it != s1.end())
    // {
    //     // *it += 1; 不允許修改
    //     cout << *it;
    //     it++;
    // }
    // cout << endl;

    bit::string s1("Hello World");
    // s1.push_back(' ');
    // s1.push_back('!');
    // for (auto ch : s1)
    // {
    //     cout << ch;
    // }
    // cout << endl;
    // s1.append("\nHello");
    // for (auto ch : s1)
    // {
    //     cout << ch;
    // }
    // cout << endl;
    // s1 += '!';
    // s1 += "\n Hello";
    // for (auto ch : s1)
    // {
    //     cout << ch;
    // }
    // cout << endl;

    // s1.insert(0, 3, '#');
    // for (auto ch : s1)
    // {
    //     cout << ch;
    // }
    // cout << endl;
    // s1.insert(0, "My World");
    // for (auto ch : s1)
    // {
    //     cout << ch;
    // }
    // cout << endl;

    s1.erase();
    for (auto ch : s1)
    {
        cout << ch;
    }
    cout << endl;
}
int main()
{
    test01();
    return 0;
}