"""
LeetCode 344. 反转字符串
难度：简单
算法：双指针
时间复杂度：O(n)
空间复杂度：O(1)
"""
from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        双指针：left从左往右，right从右往左，交换元素
        """
        left: int = 0
        right: int = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
