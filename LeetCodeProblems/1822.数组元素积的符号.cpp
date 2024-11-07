/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        // 如果数组中有0，直接返回0
        if (find(nums.begin(), nums.end(), 0) != nums.end())
            return 0;

        // 统计负数的个数
        int cnt_neg = 0;
        for (auto num : nums)
        {
            if (num < 0) // 负数计数
                ++cnt_neg;
        }

        // 如果负数个数是偶数个，返回1（正乘积），否则返回-1（负乘积）
        return cnt_neg % 2 == 0 ? 1 : -1;
    }
};
// @lc code=end

