/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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
    // 合并链表中的节点，计算每一段节点之间的和，并去除所有的0节点
    ListNode *mergeNodes(ListNode *head)
    {
        head = head->next;        // 跳过头部的0节点，开始处理有效节点
        ListNode *temp = head;    // 用temp来追踪当前合并结果的位置
        ListNode *current = head; // 用current来遍历整个链表
        int add = 0;              // 用来累加一段节点的和

        // 遍历整个链表
        while (current != nullptr)
        {
            if (current->val != 0)
            {
                // 如果当前节点的值不为0，则将值加入到add中
                add += current->val;
            }
            else
            {
                // 当遇到0节点时，说明一个区间的和已经结束
                temp->val = add;            // 将当前累计的和赋值给temp节点
                add = 0;                    // 重置add为0，准备处理下一个区间
                temp->next = current->next; // 移动temp到下一个节点
                temp = temp->next;          // 更新temp指针，指向下一个节点
            }
            current = current->next; // 移动current指针，继续遍历链表
        }
        return head; // 返回处理后的链表头节点
    }
};
// @lc code=end

