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
    vector<vector<int>> v;
    
    void BFS(TreeNode* root){
        if(root == NULL)
            return;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            TreeNode* p;
            int len = q.size();
            vector<int> v1;
            
            for(int i=0; i<len; i++){
                p = q.front();
                v1.push_back(p->val);
                
                if(p->left != NULL)
                    q.push(p->left);
                if(p->right != NULL)
                    q.push(p->right);
                q.pop();
            }
            // q.pop();
            v.push_back(v1);
        }
    }
    
    bool isEvenOddTree(TreeNode* root) {
        BFS(root);
        
        for(int i=0; i<v.size(); i++){
            if(i % 2 == 0){
                if(v[i][0] % 2 == 0)
                    return false;
                
                for(int j=1; j<v[i].size();j++){
                    if(v[i][j] <= v[i][j-1] or v[i][j] % 2 == 0)
                        return false;
                }
            }
            else{
                if(v[i][0] % 2 != 0)
                    return false;
                
                for(int j=1; j<v[i].size();j++){
                    if(v[i][j] >= v[i][j-1] or v[i][j] %2 !=0)
                        return false;
                }
            }
        }
        return true;
    }
};