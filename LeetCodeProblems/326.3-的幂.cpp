/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // 判断 n 是否大于零，并且 n 是否能整除 1162261467（3^19）
        return (n > 0) && (1162261467 % n == 0);
    }
};

// @lc code=end

