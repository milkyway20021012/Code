#include <iostream>
#include <vector>
using namespace std;

// 刪除重複項 : 快慢指針
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            ++fast;
        }
        return slow;
    }
};