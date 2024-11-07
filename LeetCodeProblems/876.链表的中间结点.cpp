/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode *middleNode(ListNode *head)
    {
        // 创建一个存储链表节点的vector，将head加入其中
        vector<ListNode *> vec = {head};

        // 遍历链表，直到链表的末尾
        while (vec.back()->next != NULL)
        {
            // 将当前节点的下一个节点加入vector
            vec.push_back(vec.back()->next);
        }

        // 返回中间节点，vec.size() / 2 是中间节点的索引
        return vec[vec.size() / 2];
    }
};

// @lc code=end

