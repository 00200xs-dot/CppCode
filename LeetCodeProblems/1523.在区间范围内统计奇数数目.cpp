/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
class Solution
{
public:
    int countOdds(int low, int high)
    {
        // 判断是否有奇数
        /* (high + 1) / 2：计算从 0 到 high（包括 high）的奇数个数。 low / 2：计算从 0 到 low - 1（不包括 low）的奇数个数。 两者的差值就是区间[low, high] 内的奇数个数。 */ return (high + 1) / 2 - low / 2;
    }
};

// @lc code=end