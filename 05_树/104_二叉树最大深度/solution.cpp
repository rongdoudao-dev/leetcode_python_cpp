/*
LeetCode 104. 二叉树的最大深度
难度：简单
算法：递归（DFS）
时间复杂度：O(n)
空间复杂度：O(h)
*/
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 递归：max(左子树深度, 右子树深度) + 1
        if (root == nullptr) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};
