#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + n, s.begin() + i);
                n = i + 1;
            }
            if (i == s.size() - 1)
            {
                reverse(s.begin() + n, s.begin() + s.size());
            }
        }
        return s;
    }
};