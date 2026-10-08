"""
LeetCode 20. 有效的括号
难度：简单
算法：栈
时间复杂度：O(n)
空间复杂度：O(n)
"""


class Solution:
    def isValid(self, s: str) -> bool:
        """
        栈：左括号入栈，右括号匹配栈顶
        """
        stack: list[str] = []
        mapping: dict[str, str] = {')': '(', '}': '{', ']': '['}
        for char in s:
            if char in mapping:
                top_element: str = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)
        return not stack
