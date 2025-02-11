// 删除链表中的中间节点  https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/description/
// 


#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};
 


// 使用快慢指针，其中快指针的移动速度是慢指针的 2 倍
ListNode* deleteMiddle(ListNode* head) 
{
    // 只有一个节点
    if (head->next == nullptr)
    {
        return nullptr;
    }
    ListNode* dummynode = new ListNode(0, head);
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = dummynode;  // 虚拟节点
    while (fast && fast->next)  // 终止条件，fast->next 必须存在，否则 slow 不会停在中间节点
    {
        prev = prev->next;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* P = slow;
    prev->next = slow->next;
    delete P;

    return head;

}
