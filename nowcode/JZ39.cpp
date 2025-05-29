#include <iostream>
using namespace std;

// 数组中出现次数超过一半的数字

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int> &numbers)
    {
        // write code here
        vector<int> v;
        v.resize(10000, 0);
        for (auto e : numbers)
        {
            v[e]++;
        }
        int max = v[0];
        int max_idx = 0;
        for (size_t i = 0; i < v.size(); ++i)
        {
            if (v[i] > max)
            {
                max_idx = i;
                max = v[i];
            }
        }
        return max_idx;
    }
};