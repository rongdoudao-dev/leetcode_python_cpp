"""
LeetCode 167. 两数之和 II - 输入有序数组
难度：简单
算法：双指针（数组已排序）
时间复杂度：O(n)
空间复杂度：O(1)
"""
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """
        双指针：left从左，right从右，和小left右移，和大right左移
        """
        left: int = 0
        right: int = len(numbers) - 1
        while left < right:
            current_sum: int = numbers[left] + numbers[right]
            if current_sum == target:
                return [left + 1, right + 1]
            elif current_sum < target:
                left += 1
            else:
                right -= 1
        return []
