"""
LeetCode 155. 最小栈
难度：中等
算法：辅助栈（同步最小值）
时间复杂度：所有操作 O(1)
空间复杂度：O(n)
"""


class MinStack:
    def __init__(self):
        """
        主栈存数据，辅助栈存当前最小值
        """
        self.main_stack: list[int] = []
        self.min_stack: list[int] = []

    def push(self, val: int) -> None:
        self.main_stack.append(val)
        current_min: int = val if not self.min_stack else min(val, self.min_stack[-1])
        self.min_stack.append(current_min)

    def pop(self) -> None:
        self.main_stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.main_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
