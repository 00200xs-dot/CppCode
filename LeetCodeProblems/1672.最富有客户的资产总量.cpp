/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max = 0;                // 用于记录当前最大财富
        int m = accounts.size();    // 客户数量（行数）
        int n = accounts[0].size(); // 每个客户的存款数目（列数）

        // 遍历每个客户
        for (int i = 0; i < m; i++)
        {
            int add = 0; // 当前客户的财富
            // 计算该客户的所有存款和
            for (int j = 0; j < n; j++)
            {
                add += accounts[i][j]; // 累加每个银行的存款
            }
            // 更新最大财富
            if (add > max)
            {
                max = add;
            }
        }

        return max; // 返回最大财富
    }
};
// @lc code=end
