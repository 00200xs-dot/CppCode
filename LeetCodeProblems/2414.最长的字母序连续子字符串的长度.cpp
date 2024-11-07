/*
 * @lc app=leetcode.cn id=2414 lang=cpp
 *
 * [2414] 最长的字母序连续子字符串的长度
 */

// @lc code=start
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        // 初始化左边界L为0，右边界R为1，L和R分别代表当前连续子串的起始和结束位置
        int L = 0, R = 1;
        size_t n = s.size(); // 字符串的长度
        int ans = 1;         // 最长连续子串的长度，初始值为1

        // 当右边界R小于字符串长度时，开始循环
        while (R < n)
        {
            // 如果当前字符和前一个字符的差不是1，说明不连续
            if (s[R] - s[R - 1] != 1)
            {
                L = R; // 更新左边界为当前右边界的位置
            }

            // 更新答案，找到最大连续子串长度
            ans = max(ans, R - L + 1);

            // 右边界向右移动
            R++;
        }

        return ans; // 返回找到的最长连续子串长度
    }
};
// @lc code=end

