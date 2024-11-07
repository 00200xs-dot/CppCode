/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size(); // 获取字符串的长度
        // 遍历所有可能的子串长度 i，从 1 开始，直到 n/2
        for (int i = 1; i * 2 <= n; ++i)
        {
            // 只有当长度 i 能整除 n 时，才可能是重复的子串
            if (n % i == 0)
            {
                bool judge = true; // 假设字符串可以由长度为 i 的子串构成
                // 从 i 开始，检查每个字符是否与前面的对应位置字符相同
                for (int j = i; j < n; ++j)
                {
                    if (s[j] != s[j - i])
                    { // 如果不相等，则说明无法构成
                        judge = false;
                        break; // 退出循环，因为已确认无法重复构成
                    }
                }
                if (judge) // 如果循环结束后 judge 仍为 true，说明可以构成重复子串
                    return true;
            }
        }
        // 如果没有找到任何符合条件的子串，返回 false
        return false;
    }
};

// @lc code=end

