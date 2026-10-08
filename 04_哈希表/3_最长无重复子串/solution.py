"""
LeetCode 3. 无重复字符的最长子串
难度：中等
算法：滑动窗口 + 哈希表
时间复杂度：O(n)
空间复杂度：O(min(m, n))，m=字符集大小
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        滑动窗口：[left, right]，哈希表记录字符最后出现位置
        """
        char_last_index: dict[str, int] = {}
        max_length: int = 0
        left: int = 0
        for right, char in enumerate(s):
            if char in char_last_index and char_last_index[char] >= left:
                left = char_last_index[char] + 1
            char_last_index[char] = right
            current_length: int = right - left + 1
            max_length = max(max_length, current_length)
        return max_length
