"""
LeetCode 322. 零钱兑换
难度：中等
算法：动态规划（完全背包）
时间复杂度：O(amount * len(coins))
空间复杂度：O(amount)
"""
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        dp[i] = 凑成金额i所需最少硬币数
        dp[i] = min(dp[i], dp[i - coin] + 1)
        """
        max_value: int = amount + 1
        dp: list[int] = [max_value] * (amount + 1)
        dp[0] = 0
        for current_amount in range(1, amount + 1):
            for coin in coins:
                if coin <= current_amount:
                    dp[current_amount] = min(dp[current_amount], dp[current_amount - coin] + 1)
        return dp[amount] if dp[amount] != max_value else -1
