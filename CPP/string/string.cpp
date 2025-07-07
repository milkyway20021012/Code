#include <iostream>
#include <string>
#include <algorithm>
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

// int main()
// {
//     // string 遍歷
//     string s("Hello World");
//     // 直接打印
//     cout << s << endl;
//     // for循環
//     for (int i = 0; i < s.size(); ++i)
//     {
//         cout << s[i];
//     }
//     cout << endl;
//     // 迭代器
//     string::iterator it = s.begin();
//     while (it != s.end())
//     {
//         cout << *it;
//         it++;
//     }
//     cout << endl;
//     // 範圍for 的底層是迭代器 => 也就是說，如果容器支持迭代器就支持範圍for 反之則不支持
//     for (auto ch : s) // 如果要使用 auto 對 s 的內容進行修改 可以使用 auto&（因爲 s 把字元給ch相當於是拷貝給ch ch的改變不影響 s
//     {
//         cout << ch;
//     }
//     cout << endl;
//     for (auto &ch : s)
//     {
//         ch++;
//         cout << ch;
//     }
//     return 0;
// }

// 迭代器：正向迭代器、反向迭代器、const 迭代器(四種)
// 反向迭代器
// int main()
// {
//     string s1 = "Hello World";
//     string::reverse_iterator rit = s1.rbegin();
//     while (rit != s1.rend())
//     {
//         cout << *rit;
//         rit++;
//     }
//     return 0;
// }

// int main()
// {
//     string s1;
//     int ret = 0;
//     for (auto e : s1)
//     {
//         if (e == ' ')
//         {
//             ret = 0;
//         }
//         else
//         {
//             ++ret;
//         }
//         cout << e << endl;
//     }
//     cout << ret;
//     return 0;
// }

// int main()
// {
//     string s1;
//     cout << s1.size();
//     return 0;
// }

// 域名分開（協議、域名、資源名）
// int main()
// {
//     string url = "https://cplusplus.com/reference/string/string/find/";
//     string protocol;
//     string domain;
//     int pos1 = url.find("://");
//     if (pos1 != string::npos)
//     {
//         protocol = url.substr(0, pos1);
//     }
//     int pos2 = url.find("/", pos1 + 3);
//     if (pos2 != string::npos)
//     {
//         domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
//         url = url.substr(pos2 + 1);
//     }
//     cout << "protocol = " << protocol << endl;
//     cout << "domain = " << domain << endl;
//     cout << "url = " << url << endl;
//     return 0;
// }

// int main()
// {
//     string s1 = "leetcode";
//     string s2 = "leet";
//     int ret = s1.find(s2);
//     cout << ret;
//     return 0;
// }

int main()
{
    string s1("ab");
    string s2("ab");

    cout << (s1 == s2) << endl;
    cout << &s1 << endl;
    cout << &s2 << endl;
    int value = 1024;
    char condition = *((char *)(&value));
    if (condition)
        value += 1;
    condition = *((char *)(&value));
    if (condition)
        value += 1;
    condition = *((char *)(&value));

    cout << value << endl;
    cout << condition << endl;
    return 0;
}
