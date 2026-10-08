"""
LeetCode 101. 对称二叉树
难度：简单
算法：递归（双树对比）
时间复杂度：O(n)
空间复杂度：O(h)
"""
from typing import Optional


class TreeNode:
    def __init__(self, val: int = 0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        """
        递归比较：左子树的左 vs 右子树的右，左子树的右 vs 右子树的左
        """
        if not root:
            return True
        return self._is_mirror(root.left, root.right)

    def _is_mirror(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if not left and not right:
            return True
        if not left or not right:
            return False
        if left.val != right.val:
            return False
        return self._is_mirror(left.left, right.right) and self._is_mirror(left.right, right.left)
