"""
LeetCode 14. 最长公共前缀
难度：简单
算法：纵向扫描
时间复杂度：O(mn)，m=字符串平均长度，n=字符串数量
空间复杂度：O(1)
"""
from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        """
        纵向扫描：逐列比较所有字符串的第i个字符
        """
        if not strs:
            return ""
        for index in range(len(strs[0])):
            current_char: str = strs[0][index]
            for string in strs[1:]:
                if index == len(string) or string[index] != current_char:
                    return strs[0][:index]
        return strs[0]
