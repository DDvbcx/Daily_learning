// 合并区间

#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (interval.empty()) return {};
        vector<vector<int>> res;

        // 首先对于区间进行排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];  // 按照区间的首个位置
        });

        for (int i = 0; i < intervals.size(); ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            if (res.empty() || res.back()[1] < l) {
                // 当前区间的左端点和 res 中的最后一个区间的右端点没有重合
                res.push_back({l, r});
            }else {
                // 当前区间的左端点和 res 中的最后一个区间的右端点没有重合
                // 直接更新区间的右端点
                res.back()[1] = max(res.back()[1], r);
            }
        }
        return res;
    }
};