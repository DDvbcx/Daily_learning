### 最小代价爬楼梯

def minCostClimbingStairs(cost: list[int]):
    dp = [0] * len(len(cost) + 1)  # 确立 dp 表

    # 初始化
    dp[0] = 0
    dp[1] = 0

    for i in range(2, len(cost) + 1):

        # 递推关系: dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
    return dp[len(cost)]