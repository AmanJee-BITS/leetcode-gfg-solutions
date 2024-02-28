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
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return 1+max(lh,rh);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<TreeNode* >q;
        q.push(root);
        int d = 0;
        vector<int> v;
        
        while(q.empty() == false){
            TreeNode* node;
            int len = q.size();
            
            for(int i =0; i<len; i++){
                node = q.front();
                if(i == 0)
                    v.push_back(node->val);

                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);

                q.pop();
            }
            
        }
        return v[v.size()-1];
    }
};