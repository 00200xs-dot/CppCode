/*
 * @lc app=leetcode.cn id=3194 lang=cpp
 *
 * [3194] 最小元素和最大元素的最小平均值
 */

// @lc code=start
class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        vector<double> averages;        // 用于存储每一对数字的平均值
        sort(nums.begin(), nums.end()); // 将数组进行排序，方便配对最小和最大值

        // 循环处理直到数组为空
        while (!nums.empty())
        {
            averages.push_back((nums.front() + nums.back()) / 2.0); // 计算当前最小值与最大值的平均值
            nums.erase(nums.begin());                               // 移除最小值
            nums.pop_back();                                        // 移除最大值
        }

        sort(averages.begin(), averages.end()); // 将所有平均值排序
        return averages.front();                // 返回最小的平均值
    }
};
// @lc code=end

