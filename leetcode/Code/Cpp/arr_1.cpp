// leetcode: https://leetcode.cn/problems/minimum-size-subarray-sum/description/
// 长度最小的子数组

#include <iostream>
#include <vector>
#include <climits>
using std::vector;

// Method 1, 暴力解题
int minSubArrayLen(int target, vector<int>& nums)
{
    // rtype: res(int)
    int res = INT32_MAX;  // 
    int sublen = 0; 
    int sum = 0;
    
    // 挨个遍历数组
    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            
            if (sum > target)
            {
                // 满足条件的子数组长度
                sublen = j - i + 1;
                res = res < sublen ? res : sublen;
                break;  // 退出，因为是连续的子数组
            }
        }
    }
    // 如果满足条件，返回 res;
    // 不满足条件，返回 0;
    return res == INT32_MAX ? 0 : res; 
}


// Method 2, 滑动窗口解题
int minSubArrayLen(int target, vector<int>& nums)
{
    // rtype: res(int)
    int res = INT32_MAX;  // 
    int sublen = 0; 
    int sum = 0;
    int i = 0;  // 窗口的起始位置

    // 窗口的末尾位置
    for (int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];
        while (sum >= target)
        {
            sublen = j - i + 1;
            res = res < sublen ? res : sublen;
            sum -= nums[i++];  //不断移动起始位置

        }
    }
    return res == INT32_MAX ? 0 : res; 

}
