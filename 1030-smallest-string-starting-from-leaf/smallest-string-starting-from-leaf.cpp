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
    void dfs(TreeNode* root, string s, string &str){
        if(root == NULL)
            return;
        
        char c = char(97 + root->val);
        s += c;
        
        if(root->left == NULL and root->right == NULL){
            reverse(s.begin(),s.end());
            if(str.size() == 0){
                str = s;
            }
            else
                str = min(str,s);
            s = "";
        }
        
        dfs(root->left, s,str);
        dfs(root->right,s,str);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        string str = "";
        
        dfs(root,s,str);
        return str;
    }
};