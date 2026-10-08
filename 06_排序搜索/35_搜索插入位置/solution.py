"""
LeetCode 35. 搜索插入位置
难度：简单
算法：二分查找
时间复杂度：O(log n)
空间复杂度：O(1)
"""
from typing import List
import bisect


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        """
        二分查找：找第一个 >= target 的位置
        """
        left: int = 0
        right: int = len(nums)
        while left < right:
            mid: int = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left
