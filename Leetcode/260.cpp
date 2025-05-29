#include <iostream>
#include <vector>
using namespace std;

// 找到出現一次的數字3
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unsigned int xor_all = 0;
        for (int x : nums)
        {
            xor_all ^= x;
        }
        int lowbit = xor_all & -xor_all; // 用来区分元素在哪一组

        vector<int> ans(2);
        for (int x : nums)
        {
            if ((x & lowbit) == 0)
            { // x 在第一组
                ans[0] ^= x;
            }
            else
            { // x 在第二组
                ans[1] ^= x;
            }
        }
        return ans;
    }
};