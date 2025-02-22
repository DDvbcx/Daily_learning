// 数组列表中的最大距离，https://leetcode.cn/problems/maximum-distance-in-arrays/description/


#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    // 初始化最大距离为 0
    int ans = 0;
    
    // 初始化 mn 和 mx
    int mn = INT_MAX / 2, mx = INT_MIN / 2;
    
    
    for (auto& arr : arrays) {
        // 更新最大距离，
        ans = max({ans, arr.back() - mn, mx - arr[0]});
        
        // 这里更新的是全局的
        mn = min(mn, arr[0]);
        mx = max(mx, arr.back());
    }
    
    
    return ans;
}