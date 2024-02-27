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

int height(TreeNode* node){
    if(node == NULL)
        return 0;
    
    return 1 + max(height(node->left), height(node->right));
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        
        return max(lh+rh, max(ld,rd));
        
    }
};