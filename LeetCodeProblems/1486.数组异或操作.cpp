/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int result = 0; // 初始化结果为 0
        for (int i = 0; i < n; i++)
        {                            // 遍历数组的每个元素
            result ^= start + 2 * i; // 将当前元素与结果进行异或操作
        }
        return result; // 返回最终的异或结果
    }
};

// @lc code=end
