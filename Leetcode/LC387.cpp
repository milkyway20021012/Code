#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int ret = -1;
        int count[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            ++count[s[i] - 97];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 97] == 1)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
};