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

// int main()
// {
//     // 增
//     string s1;
//     // s1.push_back(' ');        // 在原有的字串後插入一個字元
//     // s1.append("Hello World"); // append => 在原有的字串後插入一個字符串
//     // 更爽的用法
//     s1 += "Hello";
//     s1 += ' ';
//     s1 += "World";
//     cout << s1 << endl;
//     return 0;
// }

// 普通類和類模板的差別
// 普通類：類名相當于類名和類型 Ex: Stack
// 類模板：類名不等於類型
/*
Ex: template <class T>
// Stack -- 類名
// Stack<T> -- 類型
*/

int main()
{
    // string 遍歷
    string s("Hello World");
    // 直接打印
    cout << s << endl;
    // for循環
    for (int i = 0; i < s.size(); ++i)
    {
        cout << s[i];
    }
    cout << endl;
    // 迭代器
    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it;
        it++;
    }
    cout << endl;
    // 範圍for 的底層是迭代器 => 也就是說，如果容器支持迭代器就支持範圍for 反之則不支持
    for (auto ch : s) // 如果要使用 auto 對 s 的內容進行修改 可以使用 auto&（因爲 s 把字元給ch相當於是拷貝給ch ch的改變不影響 s
    {
        cout << ch;
    }
    cout << endl;
    for (auto &ch : s)
    {
        ch++;
        cout << ch;
    }

    return 0;
}