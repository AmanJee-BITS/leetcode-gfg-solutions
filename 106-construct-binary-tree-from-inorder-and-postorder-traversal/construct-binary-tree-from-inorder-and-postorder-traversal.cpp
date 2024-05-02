/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     unordered_map<int, int>& mp, int& postIndex, int start,
                     int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex]);
        --postIndex;

        if (start == end)
            return root;

        int inIndex = mp[root->val];

        root->right =
            helper(inorder, postorder, mp, postIndex, inIndex + 1, end);
        root->left =
            helper(inorder, postorder, mp, postIndex, start, inIndex - 1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int temp = 0;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        return helper(inorder, postorder, mp, postIndex, 0,
                      postorder.size() - 1);
    }
};