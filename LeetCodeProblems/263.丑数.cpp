/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        // 如果 n 小于等于 0，直接返回 false，因为丑数是正整数
        if (n <= 0)
            return false;

        // 通过不断除以 2，去掉所有因子 2
        while (n % 2 == 0)
            n /= 2;

        // 通过不断除以 3，去掉所有因子 3
        while (n % 3 == 0)
            n /= 3;

        // 通过不断除以 5，去掉所有因子 5
        while (n % 5 == 0)
            n /= 5;

        // 如果最后 n 等于 1，表示它只含有因子 2、3 和 5，返回 true
        // 否则，返回 false，表示它包含其他因子
        return n == 1;
    }
};

// @lc code=end

