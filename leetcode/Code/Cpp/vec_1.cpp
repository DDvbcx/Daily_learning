// 题目地址: https://leetcode.cn/problems/binary-search/description/
// 题目是一个二分搜索

#include <iostream>
#include <vector>

class Solution
{
    public:
        int search(vector<int> & nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;
            while (left <= right)  // 目标值在区间 [left, middle - 1]
            {
                int middle = left + ((right - left) / 2);
                if (nums[middle] > target)
                {
                    right = middle - 1;
                }
                else if (nums[middle] < target)  // 目标值在区间 [middle + 1, right]
                {
                    left = middle + 1;
                }
                else
                {
                    return middle;
                }
            }
            return -1;
        }
};