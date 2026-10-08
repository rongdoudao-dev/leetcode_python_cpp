/*
LeetCode 101. 对称二叉树
难度：简单
算法：递归（双树对比）
时间复杂度：O(n)
空间复杂度：O(h)
*/
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
    bool isSymmetric(TreeNode* root) {
        // 递归比较：左子树的左 vs 右子树的右，左子树的右 vs 右子树的左
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
