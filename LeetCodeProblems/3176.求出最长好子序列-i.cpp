/*
 * @lc app=leetcode.cn id=3176 lang=cpp
 *
 * [3176] 求出最长好子序列 I
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int ans = 0;         // 存储最终的结果，即可以组成的最大长度
        int n = nums.size(); // 获取输入数组 nums 的大小
        // 创建一个二维动态规划数组 dp，初始化时每个位置的值为 1
        vector<vector<int>> dp(n, vector<int>(k + 1, 1));

        // 遍历每个元素
        for (int i = 0; i < n; ++i)
        {
            // 遍历当前可以使用的最大改变次数 cnt
            for (int cnt = 0; cnt <= k; ++cnt)
            {
                // 遍历前面的所有元素，检查是否可以扩展
                for (int j = 0; j < i; ++j)
                {
                    // 如果当前元素 nums[i] 和前一个元素 nums[j] 相等，则扩展
                    if (nums[j] == nums[i])
                    {
                        dp[i][cnt] = max(dp[i][cnt], dp[j][cnt] + 1);
                    }
                    // 如果元素不相等且还有剩余的修改次数，则允许进行修改
                    else if (cnt > 0)
                    {
                        dp[i][cnt] = max(dp[i][cnt], dp[j][cnt - 1] + 1);
                    }
                }
            }
            // 更新当前的最大长度
            ans = max(ans, dp[i][k]);
        }
        return ans; // 返回结果
    }
};
// @lc code=end

