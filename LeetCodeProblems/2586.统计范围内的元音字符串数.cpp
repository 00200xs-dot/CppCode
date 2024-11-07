/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution
{
public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        // 定义一个字符串 str，包含所有元音字母，用来检查单词的首尾字母
        string str = {"aoeiu"};
        int ans = 0; // 用于存储符合条件的单词个数

        // 遍历 words 数组中索引从 left 到 right 的单词
        for (int i = left; i <= right; i++)
        {
            // 如果单词的第一个字母和最后一个字母都属于元音字母
            if (str.find(words[i][0]) != string::npos && // 判断首字母是否为元音
                str.find(words[i].back()) != string::npos)
            {          // 判断尾字母是否为元音
                ++ans; // 如果符合条件，计数加 1
            }
        }

        return ans; // 返回符合条件的单词个数
    }
};
// @lc code=end

