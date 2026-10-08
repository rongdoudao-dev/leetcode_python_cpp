"""
LeetCode 206. 反转链表
难度：简单
算法：迭代/递归
时间复杂度：O(n)
空间复杂度：O(1) 迭代 / O(n) 递归
"""
from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        迭代法：三个指针 prev, curr, next_temp
        """
        prev: Optional[ListNode] = None
        curr: Optional[ListNode] = head
        while curr:
            next_temp: Optional[ListNode] = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
        return prev
