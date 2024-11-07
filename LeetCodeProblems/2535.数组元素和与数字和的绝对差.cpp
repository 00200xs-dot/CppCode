/*
 * @lc app=leetcode.cn id=2535 lang=cpp
 *
 * [2535] 数组元素和与数字和的绝对差
 */

// @lc code=start
class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        // nums_add 用于存储数组中所有元素的和
        int nums_add = 0;
        // num_add 用于存储数组中所有元素的数字之和
        int num_add = 0;

        // 计算数组中所有元素的和
        for (auto num : nums)
        {
            nums_add += num;
        }

        // 计算数组中每个元素的数字之和
        for (auto num : nums)
        {
            // 对于每个元素 num，将其数字逐个拆开，求和
            while (num)
            {
                num_add += (num % 10); // 获取当前数字的最后一位
                num /= 10;             // 去除最后一位
            }
        }

        // 返回两者的绝对差值
        return abs(nums_add - num_add);
    }
};
// @lc code=end
