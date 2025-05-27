#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i];
    }
    cout << endl;
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it;
        it++;
    }
    cout << endl;

    for (auto e : v)
    {
        cout << e;
    }
}

void test02()
{
    vector<int> v(10, 0); // 开一个数组 初始化成0
    vector<string> strv(10, "***");

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < strv.size(); ++j)
    {
        cout << strv[j] << " ";
    }
    cout << endl;
}

void test03()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(7);
    v.push_back(4);
    // 排序 - 升序 默認使用 less
    sort(v.begin(), v.end());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // 排序 - 降序  要使用greater
    // greater<int> gt;
    sort(v.begin(), v.end(), greater<int>());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
void test04()
{
    vector<int> v;
    // 如果要使用 reserve
    v.reserve(10);
    for (size_t i = 0; i < 10; ++i)
    {
        // 不能使用 v[i] = i --- reserve 只是開空間(capacity) size 還是 0 而 operator[] 一上來就會斷言 assert(i < _size)
        v.push_back(i); // 這樣才行
    }
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v2;
    v2.resize(10); // 開空間 + 將size 設為10
    for (size_t i = 0; i < 10; ++i)
    {
        v2[i] = i;
    }
    for (auto e : v2)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test05()
{
    int a[] = {25, 3, 7, 5, 4, 3, 6, 4, 3, 3, 3, 1, 2, 4};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    // // 頭刪
    // v.erase(v.begin());
    // for (auto e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    // // 頭插
    // v.insert(v.begin(), 25);
    // for (auto e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    // 刪除3 但不知道3的位置在哪

    // vector<int>::iterator pos = find(v.begin(), v.end(), 3);
    // v.erase(pos);
    // for (auto e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    // 多個3 的情況
    vector<int>::iterator pos;
    do
    {
        pos = find(v.begin(), v.end(), 3);
        v.erase(pos);
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;

    } while (pos != v.end());
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    return 0;
}