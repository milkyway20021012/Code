#include <iostream>
#include <vector>
using namespace std;

// 找只出現一次的數字（除了出現一次的以外，其他出現三次）
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            int cnt1 = 0;
            for (auto e : nums)
            {
                cnt1 += e >> i & 1; // 先去計算每一個bit出現1的個數，不考慮x的話1的個數應為3的倍數
            }
            ans |= cnt1 % 3 << i; // 如果當前bit不是三的倍數 更新答案
        }
        return ans;
    }
};