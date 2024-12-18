### 分发糖果 https://leetcode.cn/problems/candy/description/

# 从局部最优推导出全局最优
# 这里先确保右边评分大于左边评分的情况下，让分配的糖果先满足；

# 在确保左边评分大于右边评分的情况下，让分配的糖果先满足，
# 在确定的时候，要确保能够同时满足两边，此时 max(candy_list[i], candy_list[i + 1] + 1)
# 这里的 candy_list[i] 满足大于左边，candy_list[i + 1] + 1 满足大于右边。

def candy(ratings: list[int]):
    candy_list = [1] * len(ratings)

    # 从左向右遍历
    for i in range(1, len(ratings)):
        if ratings[i] > ratings[i - 1]:
            candy_list[i] = candy_list[i - 1] + 1
    
    # 从右向左遍历
    for i in range(len(ratings) - 2, -1, -1):
        if ratings[i] > ratings[i + 1]:
            candy_list[i] = max(candy_list[i], candy_list[i + 1] + 1)
    
    res = sum(candy_list)
    return res