/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;        // 用于记录最后一个单词的长度
        int len = s.size(); // 获取字符串 s 的长度

        // 从字符串的最后一个字符向前遍历
        for (int i = len - 1; i >= 0; --i)
        {
            if (s[i] == ' ' && ans != 0)
            {
                // 遇到空格且已经开始计数，说明最后一个单词已经结束
                break;
            }
            if (s[i] != ' ')
            {
                // 如果当前字符不是空格，说明是最后一个单词的一部分
                ++ans; // 单词长度加1
            }
        }

        return ans; // 返回最后一个单词的长度
    }
};

// @lc code=end

