#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
        {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
            // 要注意迭代器的使用 s.begin() + 2 是從首元素數起的第二個元素
        }
        return s;
    }
};