/*
LeetCode 102. 二叉树的层序遍历
难度：中等
算法：BFS（队列）
时间复杂度：O(n)
空间复杂度：O(n)
*/
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS：队列存当前层节点，每层开始时记录队列大小
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            int level_size = node_queue.size();
            vector<int> current_level;
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = node_queue.front();
                node_queue.pop();
                current_level.push_back(node->val);
                if (node->left != nullptr) {
                    node_queue.push(node->left);
                }
                if (node->right != nullptr) {
                    node_queue.push(node->right);
                }
            }
            result.push_back(current_level);
        }
        return result;
    }
};
