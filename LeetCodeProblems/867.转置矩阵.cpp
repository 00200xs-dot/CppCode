/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        // 获取矩阵的行数m和列数n
        int m = matrix.size(), n = matrix[0].size();

        // 创建一个新的矩阵matrix_new，其大小为n行m列
        vector<vector<int>> matrix_new(n, vector<int>(m));

        // 遍历原矩阵，将其转置到新矩阵
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix_new[j][i] = matrix[i][j]; // 交换行列位置，实现转置
            }
        }

        // 返回转置后的矩阵
        return matrix_new;
    }
};

// @lc code=end
