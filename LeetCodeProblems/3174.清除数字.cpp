/*
 * @lc app=leetcode.cn id=3174 lang=cpp
 *
 * [3174] 清除数字
 */

// @lc code=start
class Solution
{
public:
    // clearDigits函数用于移除字符串中的数字
    string clearDigits(string s)
    {
        string ans; // 用来存储最终结果的字符串
        // 遍历输入字符串s中的每个字符
        for (char ch : s)
        {
            // 如果当前字符是数字（'0'到'9'）
            if (ch >= '0' && ch <= '9')
            {
                // 如果是数字，移除ans中最后一个字符
                ans.pop_back();
            }
            else
            {
                // 如果不是数字，将当前字符加入到ans中
                ans.push_back(ch);
            }
        }
        return ans; // 返回处理后的字符串
    }
};
// @lc code=end

