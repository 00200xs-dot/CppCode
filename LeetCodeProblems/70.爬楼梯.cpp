/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    // 主函数：爬楼梯，n 是楼梯的总阶数
    int climbStairs(int n)
    {
        // 如果只有 1 级台阶，只有一种方法，就是一步上去
        if (n == 1)
        {
            return 1;
        }
        // 如果有 2 级台阶，有两种方法，可以一次爬两步，也可以两次爬一步
        else if (n == 2)
        {
            return 2;
        }

        // 初始化，记录前两步的结果
        int onestep = 2; // 记录爬到第 n-1 阶的方式数
        int towstep = 1; // 记录爬到第 n-2 阶的方式数
        int result = 0;  // 最终的结果

        // 从第 3 阶开始，逐步推算到第 n 阶
        for (int i = 2; i < n; i++)
        {
            // 当前阶数的方式数 = 前两阶的方式数之和
            result = onestep + towstep;
            // 更新 towstep 为 onestep（即爬到 n-2 阶的方式数）
            towstep = onestep;
            // 更新 onestep 为 result（即爬到 n-1 阶的方式数）
            onestep = result;
        }

        // 返回第 n 阶的爬楼梯方式数
        return result;
    }
};
// @lc code=end
