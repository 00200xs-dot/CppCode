/*
 * @lc app=leetcode.cn id=3127 lang=cpp
 *
 * [3127] 构造相同颜色的正方形
 */

// @lc code=start
class Solution
{
public:
    // canMakeSquare函数用于判断是否可以构成一个符合要求的2x2区域
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        // 外层循环遍历2x2区域的左上角坐标
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                // 调用ans函数检查从(i, j)开始的2x2区域
                if (ans(grid, i, j))
                {
                    return true; // 如果存在符合条件的区域，返回true
                }
            }
        }
        return false; // 如果没有找到符合条件的区域，返回false
    }

    // ans函数检查指定2x2区域是否符合条件
    bool ans(vector<vector<char>> &grid, int i, int j)
    {
        int cnt_w = 0; // 计数当前2x2区域内'W'的个数

        // 遍历指定2x2区域
        for (int a = i; a <= i + 1; ++a)
        {
            for (int b = j; b <= j + 1; ++b)
            {
                // 如果当前位置是'W'，增加计数
                if (grid[a][b] == 'W')
                    ++cnt_w;
            }
        }

        // 如果'W'的个数为2，则返回false，表示不符合条件
        if (cnt_w == 2)
            return false;

        // 如果'W'的个数不为2，返回true，表示符合条件
        return true;
    }
};
// @lc code=end

