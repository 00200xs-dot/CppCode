/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        //创建单链表并使用头插法，以模仿栈的先入后出操作
        struct node
        {
            char data;//存储括号
            node *next;//指向下一个节点
        };
        
        node *headnode = nullptr;

        for (int i = 0; i < s.size(); i++)
        {
            //将三种左括号存进链表
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                node *newnode = new node();

                newnode->data = s[i];

                newnode->next = headnode;
                headnode = newnode;
            }
            else    //三种右括号与链表中的左括号匹配
            {   //链表为空，不可能匹配成功，返回false
                if (headnode == nullptr)
                {
                    return false;
                }
                
                node *temp;
                //匹配成功则删除链表中对应的左括号
                if (headnode->data == '(' && s[i] == ')' ||
                    headnode->data == '[' && s[i] == ']' ||
                    headnode->data == '{' && s[i] == '}')
                {
                    temp = headnode->next;
                    delete headnode;
                    headnode = nullptr;
                    headnode = temp;
                }
                else    //链表中的左右括号不匹配，直接返回false
                {
                    return false;
                }
            }
        }
        //s中的所有括号都处理过后，如果链表中还有元素，则说明括号不有效
        if (headnode == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
