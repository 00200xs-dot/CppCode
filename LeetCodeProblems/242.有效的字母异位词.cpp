/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int m = s.size(); // 获取字符串 s 的长度
        int n = t.size(); // 获取字符串 t 的长度

        // 如果两个字符串的长度不相等，直接返回 false
        if (m != n)
            return false;

        size_t a = 0; // 用来存储字符在字符串 s 中的位置

        // 遍历 t 中的每个字符
        for (char ch : t)
        {
            // 查找字符 ch 在字符串 s 中的位置
            a = s.find(ch);

            // 如果找到了该字符，将其替换为 '0'，表示该字符已经被使用过
            if (a != string::npos)
                s[a] = '0';
            else
                return false; // 如果找不到该字符，说明字符不匹配，返回 false
        }

        // 如果所有字符都能匹配到并被替换，说明两个字符串是字母异位词，返回 true
        return true;
    }
};

// @lc code=end

