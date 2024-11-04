/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int add = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'I')
            {
                add += 1;
            }
            if (s[i] == 'V')
            {
                add += 5;
                if (i > 0 && s[i - 1] == 'I')
                {
                    add -= 1;
                    i--;
                }
            }
            if (s[i] == 'X')
            {
                add += 10;
                if (i > 0 && s[i - 1] == 'I')
                {
                    add -= 1;
                    i--;
                }
            }
            if (s[i] == 'L')
            {
                add += 50;
                if (i > 0 && s[i - 1] == 'X')
                {
                    add -= 10;
                    i--;
                }
            }
            if (s[i] == 'C')
            {
                add += 100;
                if (i > 0 && s[i - 1] == 'X')
                {
                    add -= 10;
                    i--;
                }
            }
            if (s[i] == 'D')
            {
                add += 500;
                if (i > 0 && s[i - 1] == 'C')
                {
                    add -= 100;
                    i--;
                }
            }
            if (s[i] == 'M')
            {
                add += 1000;
                if (i > 0 && s[i - 1] == 'C')
                {
                    add -= 100;
                    i--;
                }
            }
        }
        return add;
    }
};
// @lc code=end
