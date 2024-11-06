/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 *
 * [1275] 找出井字棋的获胜者
 */

// @lc code=start
class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        // 创建数组记录下棋的地方  先初始化每个位置为0
        vector<vector<int>> a(3, vector<int>(3, 0));
        int len = moves.size();
        // 按照先A后B的顺序将moves中的每一步模拟在a中
        for (int i = 1; i <= len; ++i)
        {
            int l = moves[i - 1][0];
            int r = moves[i - 1][1];
            if (i % 2 == 1) // A走的存1
            {
                a[l][r] = 1;
            }
            else // B走的存-1
            {
                a[l][r] = -1;
            }
        }
        /*
        把a中每行每列的数据以及两条对角线的元素各自加起来，
        等于3说明A赢了等于-3说明B赢了
        */
        for (int i = 0; i < 3; ++i)
        {
            int t = 0;
            for (int j = 0; j < 3; ++j)
            {
                t += a[i][j];
            }
            if (t == 3)
                return "A";
            else if (t == -3)
                return "B";
        }
        for (int j = 0; j < 3; ++j)
        {
            int t = 0;
            for (int i = 0; i < 3; ++i)
            {
                t += a[i][j];
            }
            if (t == 3)
                return "A";
            else if (t == -3)
                return "B";
        }
        int t = a[0][0] + a[1][1] + a[2][2];
        if (t == 3)
            return "A";
        else if (t == -3)
            return "B";
        t = a[0][2] + a[1][1] + a[2][0];
        if (t == 3)
            return "A";
        else if (t == -3)
            return "B";

        // 如果len小于9，则既没有分出胜负并且还有可操作空间则返回Pending
        if (len < 9)
            return "Pending";
        return "Draw";
    }
};
// @lc code=end
