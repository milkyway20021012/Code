// 415 - 字符串相加
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        string ret;    // 输出
        int carry = 0; // 进位

        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
            int add_ret = val1 + val2 + carry;
            carry = add_ret / 10;
            add_ret %= 10;

            ret += ('0' + add_ret);
            end1--;
            end2--;
        }
        if (carry == 1)
        {
            ret += ('0' + carry);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};