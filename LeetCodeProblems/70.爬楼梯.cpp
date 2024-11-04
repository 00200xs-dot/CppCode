/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        //f(n)=f(n-1)+f(n-2)  爬楼梯问题
        //  n-1          n-2
        int onestep = 2, towstep = 1;
        int result = 0;
        for (int i = 2; i < n; i++)
        {
            result = onestep + towstep;
            towstep = onestep;
            onestep = result;
        }
        return result;
    }
};
// @lc code=end
