// 子集问题
// 题目链接: https://leetcode.cn/problems/subsets/description/ 
// 给定数组，返回所有可能的子集。 使用回溯算法

class Solution {
private:
    vector<vector<int>> res;  // 存放最终结果
    vector<int> path;

    void backtracing(vector<int>& nums; int startindex){
        res.push_back(path);  // 存放当前结果
        if (startindex >= nums.size()) {
            // 终止条件
            return;
        }

        // 从 startindex 开始，确保取过的元素不会重复
        for (int i = startindex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracing(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracing(nums, 0);
        return res;
    }
};


// 子集II 

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracing(vector<int>& nums, int startindex, vector<bool>& used) {
        res.push_back(path);
        
        for (int i = startindex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                // 如果前一个元素跟此元素相同，跳过这个元素，到下一个元素
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracing(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracing(nums, 0, used);  // 排序
        return res;
    }
};