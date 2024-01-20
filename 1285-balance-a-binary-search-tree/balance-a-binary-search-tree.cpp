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
    void dfs(TreeNode* root, vector<int>& values) {
        if (!root) return;

        dfs(root->left, values);
        values.push_back(root->val);
        dfs(root->right, values);
    }

    TreeNode* createBalanceBST(vector<int>& values, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(values[mid]);

        root->left = createBalanceBST(values, start, mid - 1);
        root->right = createBalanceBST(values, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        dfs(root, values);

        return createBalanceBST(values, 0, values.size() - 1);
    }
};