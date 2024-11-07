/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        // 如果 num 为 0，返回 0
        if (num == 0)
            return 0;

        // 如果 num 是 9 的倍数，那么数字根是 9，否则是 num 除以 9 的余数
        return (num % 9 == 0) ? 9 : (num % 9);
    }
};

// @lc code=end

