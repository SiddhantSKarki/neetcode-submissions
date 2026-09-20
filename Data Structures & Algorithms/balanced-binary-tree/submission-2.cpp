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
        return this->dfs(root)[0] == 1;
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, 0};
        }

        vector<int> left = this->dfs(root->left);
        vector<int> right = this->dfs(root->right);

        bool is_balanced = (left[0] == 1 && right[0] == 1) && abs(left[1]-right[1]) <= 1;
        int height = 1 + max(left[1], right[1]);
        return {is_balanced ? 1:0, height};
    }
};
