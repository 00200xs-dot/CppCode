/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // 如果 magazine 的大小小于 ransomNote，则直接返回 false，因为不可能构建
        if (magazine.size() < ransomNote.size())
        {
            return false;
        }

        // 创建一个长度为26的 vector，表示26个字母（a到z）的计数器
        vector<int> vec(26);

        // 遍历 magazine，将其中的字母出现次数记录到 vec 中
        for (auto &c : magazine)
        {
            vec[c - 'a']++; // 'a' 到 'z' 映射为 0 到 25
        }

        // 遍历 ransomNote，检查是否能从 magazine 中找到足够的字母
        for (auto &c : ransomNote)
        {
            vec[c - 'a']--; // 使用一个字母，数量减1
            if (vec[c - 'a'] < 0)
            { // 如果某个字母出现次数不足，返回 false
                return false;
            }
        }

        // 如果所有字母都能匹配，返回 true
        return true;
    }
};

// @lc code=end
