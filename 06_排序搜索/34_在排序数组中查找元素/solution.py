"""
LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置
难度：中等
算法：两次二分查找（左边界 + 右边界）
时间复杂度：O(log n)
空间复杂度：O(1)
"""
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        """
        找左边界：第一个 >= target
        找右边界：第一个 > target，再减1
        """
        left_bound: int = self._find_left_bound(nums, target)
        if left_bound == len(nums) or nums[left_bound] != target:
            return [-1, -1]
        right_bound: int = self._find_right_bound(nums, target) - 1
        return [left_bound, right_bound]

    def _find_left_bound(self, nums: List[int], target: int) -> int:
        left: int = 0
        right: int = len(nums)
        while left < right:
            mid: int = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left

    def _find_right_bound(self, nums: List[int], target: int) -> int:
        left: int = 0
        right: int = len(nums)
        while left < right:
            mid: int = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid
        return left
