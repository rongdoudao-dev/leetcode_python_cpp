"""
LeetCode 49. 字母异位词分组
难度：中等
算法：哈希表 + 排序键
时间复杂度：O(n * k log k)，n=字符串数，k=字符串最大长度
空间复杂度：O(n * k)
"""
from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        排序后的字符串作为key，异位词排序后相同
        """
        anagram_groups: dict[str, list[str]] = defaultdict(list)
        for string in strs:
            sorted_key: str = ''.join(sorted(string))
            anagram_groups[sorted_key].append(string)
        return list(anagram_groups.values())
