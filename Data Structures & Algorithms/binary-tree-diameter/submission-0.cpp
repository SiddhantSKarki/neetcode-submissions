/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int max_depth_l = this->depth(root->left);
        int max_depth_r = this->depth(root->right);

        int diameter = max_depth_l + max_depth_r;

        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        return max(diameter, sub);

    }

    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
};
