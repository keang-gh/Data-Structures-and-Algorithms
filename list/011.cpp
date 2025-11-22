/*
* 描述：给定单链表L:L0->L1->...->Ln-1->Ln，重新排序为：L0->Ln->->L1->Ln-1->L2->Ln-2->...
* 要求：使用原地算法，不能只改变节点内部的值，需要对实际的节点进行交换
* 思路：（1）找到链表中点
       （2）反转后半段链表
       （3）将前半段与后半段交替连接
* 周康 2025.11.14 
*/

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return;
        }

        // 步骤1:找中点
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 步骤2：分割链表并翻转后半部分
        ListNode *l2 = slow->next;
        slow->next = nullptr;
        l2 = reverseList(l2);
        
        // 步骤3：合并两段链表
        mergeLists(head, l2);
    }

    // 反转链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode *p = head;
        ListNode *q = nullptr;
        ListNode *temp = nullptr;

        while(p)
        {
            temp = p->next;
            p->next = q;

            q = p;
            p = temp;
        }
        return q;
    }

    // 合并两段链表(交替连接)
    void mergeLists(ListNode *l1,ListNode* l2)
    {
        ListNode *l1_next;
        ListNode *l2_next;

        while(l1!=nullptr && l2!=nullptr)
        {
            l1_next = l1->next;
            l2_next = l2->next;

            l1->next = l2;
            l2->next = l1_next;

            l1 = l1_next;
            l2 = l2_next;
        }
    }
};

void show(ListNode *head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);;
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    show(head);
    cout << endl;

    Solution s;
    s.reorderList(head);
    show(head);

    return 0;
}