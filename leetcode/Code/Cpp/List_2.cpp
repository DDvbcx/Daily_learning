// 移除链表中的元素  https://leetcode.cn/problems/remove-linked-list-elements/description/
// ListNode* removeElements(ListNode* head, int val) {

#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};
 

// Method 1
ListNode* removeElements(ListNode* head, int val) 
{
    // 处理头节点
    while (head != nullptr && head->val == val)
    {
        ListNode* P = head;
        head = head->next;
        delete P;

    }

    // 处理非头节点, 头结点的值不是目标值
    ListNode* cur = head;
    while (cur != nullptr && cur->next != nullptr)  // 两个条件都要满足，防止 
    {
        if (cur->next->val == val)
        {
            ListNode* P = cur->next;
            cur->next = cur->next->next;
            delete P;
        }
        else 
        {
            cur = cur->next;
        }
    }
    return head;
    
}

// Method 2 使用虚拟节点
// 跟 Method 2 中的第二种情况相同
ListNode* removeElements(ListNode* head, int val) 
{
    ListNode* dummynode = new ListNode(0, head);
    ListNode* cur = dummynode;
    while (cur != nullptr && cur->next != nullptr)
    {
        if (cur->next->val == val)
        {
            ListNode* P = cur->next;
            cur->next = cur->next->next;
            delete P;
        }
        else 
        {
            cur = cur->next;
        }
    }
    return dummynode->next;
    
}

