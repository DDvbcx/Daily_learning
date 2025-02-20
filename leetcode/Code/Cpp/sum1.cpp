// 两数之和， https://leetcode.cn/problems/two-sum/
// 给定一个数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。


// 1. 使用哈希表解题
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> rec;

    // 遍历数组
    for (int i = 0; i < nums.size(); i++) {
        
        // 
        if (rec.find(target - nums[i]) != rec.end()) {
            return {rec[target - nums[i]], i};
        }
    }

}