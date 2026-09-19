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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        deque<TreeNode*> q;

        q.push_back(root);
        while (!q.empty()) {
            int level = q.size();

            for (int i = 0; i < level; i++) {
                auto front = q.front();
                if (front) {
                    std::swap(front->left, front->right);
                    q.push_back(front->left);
                    q.push_back(front->right);
                }
                q.pop_front();
            }

        }

        return root;
    }
};
