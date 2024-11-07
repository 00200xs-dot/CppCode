/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int len = nums.size();
        double ans = INT_MIN; // 将答案初始化为特别小的数方便更新，因为存在负数元素
        double current = 0;   // 暂存窗口元素之和
        for (int t = 0, left = 0; t < len; ++t)
        {
            current += nums[t];
            // 窗口达到k大小再检查左指针
            if (t - left == k - 1)
            {
                ans = max(ans, current / k); // 计算平均数并更新最大平均数
                current -= nums[left];
                ++left;
            }
        }
        return ans;
    }
};
// @lc code=end
