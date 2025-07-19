#include <iostream>
#include <set>
#include <map>
using namespace std;

// int main()
// {
//     set<int> s = {5, 4, 3, 8, 6, 0, 7, 1};
//     auto lower = s.lower_bound(3);
//     auto upper = s.upper_bound(7);

//     s.erase(lower, upper);
//     for (auto &e : s)
//     {
//         cout << e << " ";
//     }
//     cout << endl;

//     return 0;
// }

int main()
{
    cout << "程式開始執行..." << endl;
    
    map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5}};
    cout << "初始化 map 完成，大小: " << m.size() << endl;

    m.emplace("f", 6);
    cout << "添加 'f' 後，大小: " << m.size() << endl;

    cout << "第一次遍歷 map:" << endl;
    for (auto &e : m)
    {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;

    m["a"] = 10;
    cout << "修改 'a' 的值為 10" << endl;
    
    cout << "第二次遍歷 map:" << endl;
    for (auto &e : m)
    {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;

    cout << "程式執行完成" << endl;
    return 0;
}