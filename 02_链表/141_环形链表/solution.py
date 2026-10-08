"""
LeetCode 141. 环形链表
难度：简单
算法：快慢指针（Floyd判圈算法）
时间复杂度：O(n)
空间复杂度：O(1)
"""
from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        快慢指针：slow每次走1步，fast每次走2步，相遇则有环
        """
        if not head or not head.next:
            return False
        slow: Optional[ListNode] = head
        fast: Optional[ListNode] = head.next
        while slow != fast:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
