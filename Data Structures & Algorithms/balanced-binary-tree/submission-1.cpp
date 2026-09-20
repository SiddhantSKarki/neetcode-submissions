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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int height_left_st = this->getHeight(root->left);
        int height_right_st = this->getHeight(root->right);

        if (abs(height_right_st - height_left_st) > 1) return false;

        return this->isBalanced(root->left) && this->isBalanced(root->right);
    }

    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));

    }
};
