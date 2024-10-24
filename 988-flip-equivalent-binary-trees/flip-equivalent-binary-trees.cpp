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
private:
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    
public:
    void dfs(TreeNode* root, vector<vector<int>> &v, vector<int> a){
        if(root == NULL)
            return;
        
        a.push_back(root->val);
        
        if(root->left == NULL and root->right == NULL){
            v.push_back(a);
        }
        else{
            dfs(root->left, v, a);
            dfs(root->right, v, a);
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL and root2 != NULL)
            return false;
        
        vector<int> a;
        
        dfs(root1, v1, a);
        dfs(root2, v2, a);
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        if(v1 == v2)
            return true;
        
        return false;
    }
};