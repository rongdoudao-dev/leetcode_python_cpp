"""
LeetCode 102. 二叉树的层序遍历
难度：中等
算法：BFS（队列）
时间复杂度：O(n)
空间复杂度：O(n)
"""
from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val: int = 0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        BFS：队列存当前层节点，每层开始时记录队列大小
        """
        if not root:
            return []
        result: list[list[int]] = []
        queue: deque[TreeNode] = deque([root])
        while queue:
            level_size: int = len(queue)
            current_level: list[int] = []
            for _ in range(level_size):
                node: TreeNode = queue.popleft()
                current_level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(current_level)
        return result
