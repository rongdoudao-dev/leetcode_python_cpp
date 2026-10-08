"""
LeetCode 56. 合并区间
难度：中等
算法：排序 + 贪心
时间复杂度：O(n log n)
空间复杂度：O(log n) 排序栈空间
"""
from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        """
        按左端点排序，然后贪心合并重叠区间
        """
        if not intervals:
            return []
        intervals.sort(key=lambda x: x[0])
        merged: list[list[int]] = [intervals[0]]
        for interval in intervals[1:]:
            last: list[int] = merged[-1]
            if interval[0] <= last[1]:
                last[1] = max(last[1], interval[1])
            else:
                merged.append(interval)
        return merged
