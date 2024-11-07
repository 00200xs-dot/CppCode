/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        // 定义四个变量，分别用于记录L、U、R、D的步数
        int L = 0, U = 0, R = 0, D = 0;

        // 遍历每个移动指令
        for (char &ch : moves)
        {
            if (ch == 'L')
            { // 如果是'L'，说明向左移动，L加一
                ++L;
            }
            else if (ch == 'U')
            { // 如果是'U'，说明向上移动，U加一
                ++U;
            }
            else if (ch == 'R')
            { // 如果是'R'，说明向右移动，R减一
                --R;
            }
            else if (ch == 'D')
            { // 如果是'D'，说明向下移动，D减一
                --D;
            }
        }

        // 如果L和R的步数加起来是0，并且U和D的步数加起来也是0，说明回到了原点
        if (L + R == 0 && U + D == 0)
        {
            return true; // 返回true，表示回到了原点
        }
        else
        {
            return false; // 否则返回false，表示没有回到原点
        }
    }
};
// @lc code=end
