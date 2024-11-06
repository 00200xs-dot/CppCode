/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */

// @lc code=start
class Solution
{
public:
    string losingPlayer(int x, int y)
    {
        // 无论谁进行操作都需要一个75（x）和四个10（y）
        int times = min(x, y / 4); // 计算游戏次数
        return times % 2 == 1 ? "Alice" : "Bob";
        // 两个人都进行操作之后，还有一次游戏次数的话
        // 则Alice胜利，反之Bob胜利
    }
};
// @lc code=end
