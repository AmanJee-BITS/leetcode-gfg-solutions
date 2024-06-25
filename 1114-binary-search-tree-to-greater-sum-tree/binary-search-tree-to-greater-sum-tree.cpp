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
    void inOrder(TreeNode* root, vector<int> &v){
        if(root == NULL)
            return;
        
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    
    void sumTree(TreeNode* root, vector<pair<int,int>> &p, int &t){
        if(root == NULL)
            return;
        
        sumTree(root->left,p,t);
        
        if(t < 1){
            root->val = p[t].second;
        }
        else{
            root->val = p[t-1].second - p[t-1].first;
        }
        t++;        
        sumTree(root->right,p,t);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        
        vector<pair<int, int>> p;
        
        int t =0;
        int sum = 0;
        
        for(int i = v.size()-1; i>=0; i--){
            sum += v[i];
            
            p.push_back(make_pair(v[i], sum));
        }
        
        reverse(p.begin(), p.end());
        
        sumTree(root,p,t);
        
        return root;
    }
};