#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 找出數組中出現一次的數字
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int idx = 0;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i + 1] == nums[i] || (i != 0 && nums[i - 1] == nums[i]))
            {
                continue;
            }
            else
            {
                idx = i;
                break;
            }
        }
        return nums[idx];
    }
};

// 第二種解法 : 找一個 且其他的出現兩次 => 想到XOR 高效率解法
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int value = 0;
        for (auto e : nums)
        {
            value ^= e;
        }
        return value;
    }
};