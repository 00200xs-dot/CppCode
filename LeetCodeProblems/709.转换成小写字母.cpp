/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution
{
public:
    string toLowerCase(string s)
    {
        // 遍历字符串中的每一个字符
        for (int i = 0; i < s.size(); i++)
        {
            // 如果字符是大写字母（ASCII码范围是 65 到 90）
            if (s[i] >= 65 && s[i] <= 90)
            {
                // 将字符转换为小写字母
                s[i] += 32; // ASCII 值差异：大写字母与小写字母相差 32
            }
        }
        // 返回转换后的字符串
        return s;
    }
};

// @lc code=end
