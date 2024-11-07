/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result; // 创建一个空的结果数组
        for (int i = 0; i < nums.size(); i++)
        {                // 遍历原数组的每个元素
            int add = 0; // 累加的临时变量
            for (int t = 0; t <= i; t++)
            {                   // 从0到i的每个元素累加
                add += nums[t]; // 累加当前元素
            }
            result.push_back(add); // 将累加和加入结果数组
        }
        return result; // 返回最终的累加结果数组
    }
};

// @lc code=end
