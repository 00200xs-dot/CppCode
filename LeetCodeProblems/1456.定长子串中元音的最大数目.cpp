/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        string c = "aeiou"; // 元音字母用于比较
        int len = s.size();
        int ans = 0;
        int current = 0; // 临时记录元音字母数量
        // temp是窗口右指针 left是窗口左指针
        for (int temp = 0, left = 0; temp < len; ++temp)
        {
            // 窗口大小大于k时向右移动左指针left
            // 并且判断被移除的字母是不是元音 更新临时元音字母数量current
            if (temp - left == k)
            {
                auto t = c.find(s[left]);
                if (t != string::npos)
                {
                    --current;
                }
                ++left;
            }
            // 移动右指针temp并更新current
            auto pos = c.find(s[temp]);
            if (pos != string::npos)
            {
                ++current;
            }
            // 更新ans的值
            ans = max(ans, current);
        }
        return ans;
    }
};
// @lc code=end
