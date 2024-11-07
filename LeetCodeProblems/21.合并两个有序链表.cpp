/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *tempc = nullptr; // 指向合并后链表的当前节点
        ListNode *pc = nullptr;    // 指向合并后链表的头节点
        ListNode *temp1 = list1;   // 遍历list1的指针
        ListNode *temp2 = list2;   // 遍历list2的指针

        // 如果其中一个链表为空，直接返回另一个链表
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // 确定合并后的链表的头节点
        if (temp1->val <= temp2->val)
        {
            pc = temp1;          // 头节点为list1的第一个节点
            tempc = temp1;       // 当前节点也指向list1的第一个节点
            temp1 = temp1->next; // 移动temp1指针
        }
        else
        {
            pc = temp2;          // 头节点为list2的第一个节点
            tempc = temp2;       // 当前节点也指向list2的第一个节点
            temp2 = temp2->next; // 移动temp2指针
        }

        // 遍历两个链表，按大小合并
        while (temp1 && temp2)
        { // 当两个链表都未遍历完
            if (temp1->val <= temp2->val)
            {
                tempc->next = temp1; // 将temp1节点接到合并链表后
                temp1 = temp1->next; // 移动temp1指针
                tempc = tempc->next; // 更新tempc为合并链表的最后一个节点
            }
            else
            {
                tempc->next = temp2; // 将temp2节点接到合并链表后
                temp2 = temp2->next; // 移动temp2指针
                tempc = tempc->next; // 更新tempc为合并链表的最后一个节点
            }
        }

        // 如果有链表未遍历完，直接将剩余部分连接到合并链表后
        if (temp1 == nullptr)
        {                        // 如果list1遍历完了
            tempc->next = temp2; // 直接连接list2的剩余部分
        }
        else
        {                        // 如果list2遍历完了
            tempc->next = temp1; // 直接连接list1的剩余部分
        }

        return pc; // 返回合并后的链表头节点
    }
};

// @lc code=end
