/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int ans = 0;        // 初始化结果为 0
        int n = mat.size(); // 获取矩阵的大小（假设矩阵是方阵）

        // 计算主对角线的和
        for (int i = 0; i < n; ++i)
        {
            ans += mat[i][i]; // 主对角线元素为 (i, i)，直接累加
        }

        // 计算副对角线的和
        for (int i = 0, j = n - 1; i < n; ++i, --j)
        {
            ans += mat[i][j]; // 副对角线元素为 (i, n-i-1)，直接累加
        }

        // 如果矩阵的大小是奇数，减去重复计算的中心元素
        if (n % 2 == 1)
        {
            ans -= mat[(n - 1) / 2][(n - 1) / 2]; // 中心元素 (n-1)/2, (n-1)/2
        }

        return ans; // 返回对角线元素的和
    }
};
// @lc code=end

