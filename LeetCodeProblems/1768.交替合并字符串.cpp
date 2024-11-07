/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;         // 存储最终的交替合并字符串
        int w1 = 0, w2 = 0; // 用于遍历两个字符串的指针

        // 交替合并两个字符串，直到其中一个字符串被完全合并
        while (w1 < word1.size() && w2 < word2.size())
        {
            ans += word1[w1++]; // 添加word1当前字符
            ans += word2[w2++]; // 添加word2当前字符
        }

        // 如果word1还有剩余，直接添加到结果中
        while (w1 < word1.size())
        {
            ans += word1[w1++];
        }

        // 如果word2还有剩余，直接添加到结果中
        while (w2 < word2.size())
        {
            ans += word2[w2++];
        }

        return ans; // 返回交替合并后的字符串
    }
};
// @lc code=end

