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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return 0;
        
       int x = 0;
        int* sum = &x;
        helper(root,L,R,sum);
        return x;
    }
     
    void helper(TreeNode* root, int L, int R, int* sum){
        if(root==NULL)
            return;
        if(root->val>=L && root->val<=R)
            *sum+=root->val;
        
        helper(root->left,L,R,sum);
        helper(root->right,L,R,sum);
    }
};