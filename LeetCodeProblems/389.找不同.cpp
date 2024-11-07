/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        size_t result; // 用于存储字符查找的结果
        char ch;       // 用于存储当前遍历到的字符

        // 遍历 t 字符串的每个字符
        for (int i = 0; i < t.size(); ++i)
        {
            ch = t[i]; // 记录当前的字符

            // 查找字符 ch 在 s 字符串中的位置
            result = s.find(ch);

            // 如果找不到这个字符，说明这个字符是多出来的，直接返回
            if (result == string::npos)
                break;
            else
                s[result] = '0'; // 找到这个字符，就在 s 中将其“标记”掉，用 '0' 代替
        }

        return ch; // 返回 t 中的那个多出来的字符
    }
};

// @lc code=end

