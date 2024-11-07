/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        size_t len = digits.size(); // 获取数组长度

        digits.back()++; // 将最后一个元素加1

        if (digits.back() < 10) // 如果加1后的末位没有进位
            return digits;      // 直接返回结果

        // 如果需要处理进位
        for (int i = len - 1; i >= 0; --i)
        { // 从末位开始向前遍历
            if (digits[i] == 10)
            {                  // 检查当前位是否为10（需要进位）
                digits[i] = 0; // 将当前位设置为0

                if (i - 1 >= 0)
                {                    // 如果不是首位
                    digits[i - 1]++; // 前一位加1
                }
                else
                {                                     // 如果是首位
                    digits.insert(digits.begin(), 1); // 在首位插入1，处理如999变成1000的情况
                }
            }
            else
            {                  // 如果当前位不需要进位
                return digits; // 直接返回结果
            }
        }

        return digits; // 最终返回加1后的数组
    }
};

// @lc code=end

