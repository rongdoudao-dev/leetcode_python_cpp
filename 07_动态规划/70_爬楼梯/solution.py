"""
LeetCode 70. 爬楼梯
难度：简单
算法：动态规划（斐波那契数列）
时间复杂度：O(n)
空间复杂度：O(1) 滚动数组优化
"""


class Solution:
    def climbStairs(self, n: int) -> int:
        """
        dp[i] = dp[i-1] + dp[i-2]，用滚动数组优化空间
        """
        if n <= 2:
            return n
        prev_two: int = 1
        prev_one: int = 2
        for _ in range(3, n + 1):
            current: int = prev_one + prev_two
            prev_two = prev_one
            prev_one = current
        return prev_one
