"""
LeetCode 21. 合并两个有序链表
难度：简单
算法：虚拟头节点 + 双指针
时间复杂度：O(n+m)
空间复杂度：O(1)
"""
from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
        虚拟头节点 dummy，比较两个链表当前节点值，小的接在后面
        """
        dummy: ListNode = ListNode(0)
        current: ListNode = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        current.next = list1 if list1 else list2
        return dummy.next
