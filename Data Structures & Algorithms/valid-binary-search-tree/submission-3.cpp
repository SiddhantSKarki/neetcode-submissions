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
    bool isValidBST(TreeNode* root) {
        // return dfs(root, LONG_MIN, LONG_MAX);
        return bfs(root);

    }

    bool bfs(TreeNode* root) {
        if (!root) {
            return true;
        }

        deque<tuple<TreeNode*, long, long>> dq;
        dq.push_back(make_tuple(root, LONG_MIN, LONG_MAX));

        while (!dq.empty()) {
            auto [node, min, max] = dq.front();
            dq.pop_front();

            if (!(min < node->val && node->val < max)) {
                return false;
            }
            
            if (node->left) {
                dq.push_back(make_tuple(node->left, min, node->val));
            }

            if (node->right) {
                dq.push_back(make_tuple(node->right, node->val, max));
            }
        }

        return true;
    }

    bool dfs(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }

        if (!(root->val > min && root->val < max)) {
            return false;
        }

        bool left = this->dfs(root->left, min, root->val);
        bool right = this->dfs(root->right, root->val, max);

        return left && right;
    }
};
