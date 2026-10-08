"""
LeetCode 104. 二叉树的最大深度
难度：简单
算法：递归（DFS）
时间复杂度：O(n)
空间复杂度：O(h)，h=树高
"""
from typing import Optional


class TreeNode:
    def __init__(self, val: int = 0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        递归：max(左子树深度, 右子树深度) + 1
        """
        if not root:
            return 0
        left_depth: int = self.maxDepth(root.left)
        right_depth: int = self.maxDepth(root.right)
        return max(left_depth, right_depth) + 1
