/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int H = haystack.length(); // 获取主字符串 haystack 的长度
        int N = needle.length();   // 获取子字符串 needle 的长度

        // 早期优化：如果主串长度小于子串长度，则必定无法匹配，直接返回 -1
        // if (H < N) {
        //     return -1;
        // }

        // 在 haystack 中寻找 needle 的起始位置
        // i 的取值范围为 [0, H - N]，因为从 H - N 开始的子串才有可能包含完整的 needle
        for (int i = 0; i <= H - N; i++)
        {
            bool test = true; // 标记当前子串是否匹配

            // 内层循环，比较从 haystack[i] 开始的子串是否与 needle 匹配
            for (int j = 0; j < N; j++)
            {
                if (haystack[i + j] != needle[j])
                {                 // 如果任一字符不匹配
                    test = false; // 标记不匹配
                    break;        // 退出内层循环，检查下一个子串
                }
            }

            if (test)
            {             // 如果当前子串完全匹配
                return i; // 返回起始索引 i
            }
        }

        // 如果循环结束还未找到匹配子串，返回 -1 表示 needle 不在 haystack 中
        return -1;
    }
};

// @lc code=end

