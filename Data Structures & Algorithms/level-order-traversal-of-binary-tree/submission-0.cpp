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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> level_order;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 0;
        while (!dq.empty()) {
            level = dq.size();
            vector<int> temp;
            for (int i = 0; i < level; i++) {
                auto front = dq.front();
                dq.pop_front();
                if (front) {
                    temp.push_back(front->val);
                    if (front->left) dq.push_back(front->left);
                    if (front->right) dq.push_back(front->right);
                }
            }
            level_order.push_back(temp);
        }

        return level_order;   
    }
};
