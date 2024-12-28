#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/* 最小路径和: 暴力搜索 */
int minPathSumDFS(vector<vector<int>>& grid , int i, int j) {
    // 左上角的元素
    if (i == 0 && j == 0) {
        return grid[0][0];
    }

    // 终止条件
    if (i < 0 || j < 0) {
        return INT_MAX;
    }

    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);

    return min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
}

/* 记忆化搜索 */
int minPathSumDFSMen(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j) {
    // 为左上角单元格，终止搜索
    if (i == 0 && j == 0) {
        return grid[0][0];
    }

    // 终止条件
    if (i < 0 || j < 0) {
        return INT_MAX;
    }

    if (mem[i][j] != -1) {
        return mem[i][j];
    }

    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);

    mem[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
    return mem[i][j];
}

/* 动态规划 */
int minPathSumDP(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    // 初始化 dp 表
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = dp[0][0];

    // 状态转移: 首行
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // 状态转移: 首列
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // 状态转移
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    return dp[n - 1][m - 1];
    }
}
