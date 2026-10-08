"""
LeetCode 622. 设计循环队列
难度：中等
算法：数组 + 双指针（head/tail）
时间复杂度：所有操作 O(1)
空间复杂度：O(k)
"""


class MyCircularQueue:
    def __init__(self, k: int):
        """
        循环队列：固定大小数组，head指向队首，tail指向队尾下一个位置
        留一个空位区分空和满
        """
        self._capacity: int = k + 1
        self._queue: list[int] = [0] * self._capacity
        self._head: int = 0
        self._tail: int = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self._queue[self._tail] = value
        self._tail = (self._tail + 1) % self._capacity
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self._head = (self._head + 1) % self._capacity
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self._queue[self._head]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self._queue[(self._tail - 1 + self._capacity) % self._capacity]

    def isEmpty(self) -> bool:
        return self._head == self._tail

    def isFull(self) -> bool:
        return (self._tail + 1) % self._capacity == self._head
