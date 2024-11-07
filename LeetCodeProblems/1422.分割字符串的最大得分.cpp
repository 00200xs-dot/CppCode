/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {
        int maxans = 0; // 存储最终的最大分数
        for (int i = 1; i < s.size(); ++i)
        {                            // 从第一个字符开始遍历，分割字符串
            int left = 0, right = 0; // 初始化左边（left）和右边（right）的计数
            for (int l = 0; l < i; ++l)
            { // 计算左边（0的个数）
                if (s[l] == '0')
                    left++;
            }
            for (int r = i; r < s.size(); ++r)
            { // 计算右边（1的个数）
                if (s[r] == '1')
                    right++;
            }
            maxans = max(maxans, left + right); // 更新最大分数
        }
        return maxans; // 返回最大分数
    }
};

// @lc code=end
