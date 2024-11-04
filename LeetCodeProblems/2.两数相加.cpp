/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = nullptr;
        ListNode *temp1 = l1;
        vector<int> list1;
        while (temp1 != nullptr)
        {
            list1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        ListNode *temp2 = l2;
        vector<int> list2;
        while (temp2 != nullptr)
        {
            list2.push_back(temp2->val);
            temp2 = temp2->next;
        }
        vector<int> res{0};
        for (int i = 1; i <= max(list1.size(), list2.size()); ++i)
        {
            if (i <= min(list1.size(), list2.size()))
            {
                res[i - 1] += (list1[i - 1] + list2[i - 1]) % 10;
                if (list1[i - 1] + list2[i - 1] >= 10)
                {
                    res[i] = 1;
                }
                else
                {
                    res[i] = 0;
                }
            }
            else if (list1.size() > list2.size())
            {
                res.push_back(list1[i - 1]);
            }
            else if (list2.size() > list1.size())
            {
                res.push_back(list2[i - 1]);
            }
        }
        for (auto num : res)
        {
            ListNode *newnode = new ListNode(num, ans);
            ans = newnode;
        }
        return ans;
    }
};
// @lc code=end
