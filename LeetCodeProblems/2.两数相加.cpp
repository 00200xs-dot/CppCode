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
    // 主函数：接收两个链表 l1 和 l2，返回它们的和，以链表形式存储
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 最终结果链表
        ListNode *ans = nullptr;

        // 将 l1 转换为向量 list1
        ListNode *temp1 = l1;
        vector<int> list1;
        while (temp1 != nullptr)
        {
            list1.push_back(temp1->val); // 将链表节点的值存入 list1
            temp1 = temp1->next;         // 移动到下一个节点
        }

        // 将 l2 转换为向量 list2
        ListNode *temp2 = l2;
        vector<int> list2;
        while (temp2 != nullptr)
        {
            list2.push_back(temp2->val); // 将链表节点的值存入 list2
            temp2 = temp2->next;         // 移动到下一个节点
        }

        // 用于存储结果的向量 res，初始化为 {0}
        vector<int> res{0};

        // 通过逐位加法计算两链表和的各个位
        for (int i = 1; i <= max(list1.size(), list2.size()); ++i)
        {
            if (i <= min(list1.size(), list2.size()))
            {
                // 如果两个链表在当前位都有数字
                res[i - 1] += (list1[i - 1] + list2[i - 1]) % 10; // 求当前位的和并对10取余
                if (list1[i - 1] + list2[i - 1] >= 10)
                {               // 如果超过10，需要进位
                    res[i] = 1; // 进位
                }
                else
                {
                    res[i] = 0; // 不需要进位
                }
            }
            else if (list1.size() > list2.size())
            {
                // 如果 l1 比 l2 长，直接将 l1 剩余部分加到结果中
                res.push_back(list1[i - 1]);
            }
            else if (list2.size() > list1.size())
            {
                // 如果 l2 比 l1 长，直接将 l2 剩余部分加到结果中
                res.push_back(list2[i - 1]);
            }
        }

        // 根据结果向量 res 创建新的链表
        for (auto num : res)
        {
            ListNode *newnode = new ListNode(num, ans); // 创建新节点，连接到 ans 链表的前面
            ans = newnode;                              // 更新 ans 为新节点
        }

        // 返回计算好的链表
        return ans;
    }
};
// @lc code=end
