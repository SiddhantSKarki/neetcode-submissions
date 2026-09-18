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
    int maxDepth(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        std::deque<TreeNode*> dq;
        dq.push_back(root);
        int height = 0;
        while (!dq.empty()) {
            int level = dq.size();

            for (int i = 0; i < level; i++) {
                auto node = dq.front();
                
                dq.pop_front();

                if (node->left) {
                    dq.push_back(node->left);
                }

                if (node->right) {
                    dq.push_back(node->right);
                }
            }

            height++;
        }

        return height;
    }
};
