/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 *
 * [2413] 最小偶倍数
 */

// @lc code=start
class Solution
{
public:
    // 函数用于找出最小的可以被 n 整除的偶数倍数
    int smallestEvenMultiple(int n)
    {
        // 如果 n 本身是偶数，则最小的偶数倍数就是 n 本身
        if (n % 2 == 0)
        {
            return n; // 直接返回 n，因为它本身就是偶数
        }
        // 如果 n 是奇数，则最小的偶数倍数是 n 的两倍
        else
        {
            return n * 2; // 返回 n * 2，因为偶数倍数最小的就是 n 的两倍
        }
    }
};
// @lc code=end

