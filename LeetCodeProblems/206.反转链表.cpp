/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        // 如果链表为空或者只有一个节点，直接返回头节点（不用反转）
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp1 = head;       // temp1 用来跟踪当前节点
        ListNode *temp2 = head->next; // temp2 用来跟踪下一个节点
        ListNode *temp3 = nullptr;    // temp3 用来暂存下一个节点（防止丢失）

        temp1->next = nullptr; // 将当前节点的 next 指针设为 nullptr，因为反转后它将成为尾节点

        // 当 temp2 不为空时，开始循环反转
        while (temp2 != nullptr)
        {
            temp3 = temp2->next; // 暂存下一个节点
            temp2->next = temp1; // 将当前节点的 next 指针指向 temp1，从而反转链表

            temp1 = temp2; // 将 temp1 移动到下一个节点
            temp2 = temp3; // 将 temp2 移动到下一个节点
        }

        // 当 temp2 为 nullptr 时，意味着反转已完成，temp1 现在是新的头节点
        head = temp1; // 更新链表的头指针
        return head;  // 返回反转后的链表头
    }
};

// @lc code=end

