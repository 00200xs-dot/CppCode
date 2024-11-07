/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int current = 0; // 当前窗口中元素之和
        int cnt = 0;     // 满足题意的子数组数量
        int len = arr.size();
        int a = threshold * k;
        for (int t = 0, left = 0; t < len; ++t)
        {
            current += arr[t];

            if (t < k - 1) // 窗口大小不足k则继续移动右指针
                continue;

            if (current >= a) // 当前窗口满足题意平均值大于threshold则更新cnt
                ++cnt;
            // 移动左指针
            current -= arr[left];
            ++left;
        }
        return cnt;
    }
};
// @lc code=end
