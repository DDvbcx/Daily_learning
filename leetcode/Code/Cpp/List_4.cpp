// 链表最大孪生和  https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/description/

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using std::vector;
int pairSum(ListNode* head) 
{
    ListNode* cur = head;
    vector<int> tmp;
    while (cur != nullptr)
    {
        tmp.push_back(cur->val);
        cur = cur->next;
    }
    int max_val = INT_MIN;
    int sum = 0;
    int i = 0, j = tmp.size() - 1;  // 左右指针

    while(i < j)
    {
        sum = tmp[i] + tmp[j];
        max_val = std::max(max_val, sum);  // 更新最大值;
        i++;
        j--;
    }
    return max_val;
    
}