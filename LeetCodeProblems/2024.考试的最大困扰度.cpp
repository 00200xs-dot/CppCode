/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution
{
public:
    // 辅助函数：计算在最多改变k次字符后，最长的连续目标字符（target）的子串长度
    int answer(string answerKey, int k, char target)
    {
        int ans = 0; // 用于存储最长连续子串的长度
        int cnt = 0; // 当前窗口中，非目标字符的数量
        // 使用滑动窗口，right表示窗口的右边界
        for (int left = 0, right = 0; right < answerKey.size(); ++right)
        {
            // 如果当前字符不是目标字符（target），则增加cnt
            if (answerKey[right] != target)
                ++cnt;

            // 当非目标字符的数量超过k时，收缩窗口的左边界
            while (cnt > k)
            {
                // 如果左边界的字符不是目标字符，减小cnt
                if (answerKey[left++] != target)
                    --cnt;
            }

            // 更新最长子串长度，窗口大小即为right - left + 1
            ans = max(ans, right - left + 1);
        }
        return ans; // 返回最大连续子串的长度
    }

    // 主函数：计算可以得到的最长连续相同字符子串（'T' 或 'F'）
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        // 计算连续 'T' 和 'F' 字符的最长子串长度，返回较大的一个
        return max(answer(answerKey, k, 'T'), answer(answerKey, k, 'F'));
    }
};
// @lc code=end

