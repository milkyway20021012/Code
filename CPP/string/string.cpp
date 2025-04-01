#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//     string s1; // 調用 string();
//     string s2("Hello World");
//     string s3(s2, 6, 5); // 如果沒有給第三個參數默認是無符號的 -1 位置從0開始數起
//     string s4(10, '*');  // n 個字元
//     cout << s1 << endl;
//     cout << s2 << endl;
//     cout << s3 << endl;
//     cout << s4 << endl;
//     return 0;
// }

int main()
{
    // 增
    string s1;
    // s1.push_back(' ');        // 在原有的字串後插入一個字元
    // s1.append("Hello World"); // append => 在原有的字串後插入一個字符串

    // 更爽的用法
    s1 += "Hello";
    s1 += ' ';
    s1 += "World";
    cout << s1 << endl;

    return 0;
}