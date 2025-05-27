#include <iostream>
#include <string>
using namespace std;
// 把字符串轉換成整數
class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0, sz = str.size();
        // 跳过前导空格
        while (i < sz && str[i] == ' ')
        {
            i++;
        }
        // 判断第一个非空格位是加号或减号
        int sign = 1;
        if (i < sz && (str[i] == '-' || str[i] == '+'))
        {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        // 转换数字
        long result = 0;
        while (i < sz && isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
            i++;
            if (result * sign >= INT_MAX)
                return INT_MAX;
            if (result * sign <= INT_MIN)
                return INT_MIN;
        }
        return result * sign;
    }
};