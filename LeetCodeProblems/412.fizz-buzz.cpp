/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        int i = 1;          // 从1开始
        vector<string> ans; // 用来存储最终结果
        ans.reserve(n);     // 预先分配空间，这样可以提高效率，避免多次扩容

        // 循环从 1 到 n
        while (i <= n)
        {
            // 如果 i 是 3 和 5 的倍数，加入 "FizzBuzz"
            if (i % 3 == 0 && i % 5 == 0)
            {
                ans.push_back("FizzBuzz");
            }
            // 如果 i 只是 3 的倍数，加入 "Fizz"
            else if (i % 3 == 0)
            {
                ans.push_back("Fizz");
            }
            // 如果 i 只是 5 的倍数，加入 "Buzz"
            else if (i % 5 == 0)
            {
                ans.push_back("Buzz");
            }
            // 如果 i 既不是 3 的倍数也不是 5 的倍数，加入 i 的字符串
            else
            {
                ans.push_back(to_string(i));
            }

            i++; // 自增 i，进行下一个数的判断
        }

        // 返回最终结果
        return ans;
    }
};

// @lc code=end
