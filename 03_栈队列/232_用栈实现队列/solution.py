"""
LeetCode 232. 用栈实现队列
难度：简单
算法：双栈（输入栈 + 输出栈）
时间复杂度：push O(1)，pop 均摊 O(1)
空间复杂度：O(n)
"""


class MyQueue:
    def __init__(self):
        """
        两个栈：input_stack负责入队，output_stack负责出队
        """
        self.input_stack: list[int] = []
        self.output_stack: list[int] = []

    def push(self, x: int) -> None:
        self.input_stack.append(x)

    def pop(self) -> int:
        self._move_input_to_output()
        return self.output_stack.pop()

    def peek(self) -> int:
        self._move_input_to_output()
        return self.output_stack[-1]

    def empty(self) -> bool:
        return not self.input_stack and not self.output_stack

    def _move_input_to_output(self) -> None:
        """输出栈为空时，把输入栈全部倒入输出栈"""
        if not self.output_stack:
            while self.input_stack:
                self.output_stack.append(self.input_stack.pop())
