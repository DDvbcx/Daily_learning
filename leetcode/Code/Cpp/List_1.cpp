// 环形链表
// 给定链表的头节点 head，判断链表中是否有环。

// 这里使用 快慢指针法，如果有环，fast 指针先入环中，
// fast 和 slow 相遇一定是在环中相遇的


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // 两个指针相遇
            if (slow==fast) return true;
        }
        return false;
        
    }
};