/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // 判断条件：n 大于 0 且 n 与 (n - 1) 按位与的结果为 0
        return (n > 0) && (n & (n - 1)) == 0;
    }
};

// @lc code=end

