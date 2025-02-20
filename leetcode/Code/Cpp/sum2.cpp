// 三数之和， https://leetcode.cn/problems/3sum/
// 给定一个包含 n 个整数的数组 nums，
// 判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
// 找出所有满足条件且不重复的三元组。

// 1. 使用双指针解题
// 这里返回的是元素值，而不是下表，所以我们可以使用双指针的方法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    // 排序
    sort(nums.begin(), nums.end());

    // 遍历元素中的指针，然后将问题转化为两数之和
    for (int i = 0; i < nums.size(); i++) {
        
        // 三元组，如果前后两个元素相同，则可直接跳过后一个相同元素
        // 因为前一个相同的元素会将所有情况都尝试
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // 同时满足索引要求
        int target = -nums[i];
        int l = i + 1, r = nums.size() - 1;

        while (l < r)
        {
            if (nums[l] + nums[r] == target) {
                // 满足条件
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;  // r + 1 ，因为是已经使用的
            } else if (nums[l] + nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        
    }
    return ans;
}
