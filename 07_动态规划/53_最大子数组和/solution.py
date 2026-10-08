"""
LeetCode 53. 最大子数组和
难度：中等
算法：动态规划（Kadane算法）
时间复杂度：O(n)
空间复杂度：O(1)
"""
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        dp[i] = max(nums[i], dp[i-1] + nums[i])
        即：要么从当前重新开始，要么接上之前的
        """
        max_sum: int = nums[0]
        current_sum: int = nums[0]
        for num in nums[1:]:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)
        return max_sum
