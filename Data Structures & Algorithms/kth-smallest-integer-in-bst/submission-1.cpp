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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }
        // vector<int> helper;
        // dfs(root, helper);
        // return helper[k - 1];

        stack<TreeNode*> st;
        int counter = k;

        TreeNode* node = root;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            counter--;
            if (counter == 0) {
                return node->val;
            }
            node = node->right;
        }

        return -1;
    }

    void dfs(TreeNode* node, vector<int>& helper) {
        if (!node) {
            return;
        }
        dfs(node->left, helper);
        helper.push_back(node->val);
        dfs(node->right, helper);
    }
};
