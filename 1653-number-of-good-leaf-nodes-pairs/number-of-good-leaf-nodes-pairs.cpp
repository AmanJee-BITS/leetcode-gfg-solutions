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
    vector<TreeNode *> leaf;
    unordered_map<TreeNode *,int> finder;
    unordered_map<TreeNode *,vector<TreeNode *>> mp;
    set<pair<TreeNode *,TreeNode *>> ans;
    int d;

    public:
    void tree(TreeNode *root)
    {
        if(root==NULL)
            return;
        if(root->left)
            mp[root].push_back(root->left),mp[root->left].push_back(root);
        if(root->right)
            mp[root].push_back(root->right),mp[root->right].push_back(root);
        if(root->left==NULL&&root->right==NULL)
        {
            leaf.push_back(root);
            finder[root]++;
            return;
        }
        tree(root->left);
        tree(root->right);
    }
    void dfs(TreeNode *root,TreeNode *p,TreeNode *base,int dis)
    {
        if(dis>d)
            return;
        if(base!=root&&finder[root])
        {
                 if(dis<=d&&ans.find({base,root})==ans.end()&&ans.find({root,base})==ans.end())
            {
                ans.insert({base,root});
            }
        }
        for(int i=0;i<mp[root].size();i++)
        {
            if(mp[root][i]!=p)
            {
                dfs(mp[root][i],root,base,dis+1);
            }
        }
    }
    int countPairs(TreeNode* root, int distance) {
        tree(root);
        d=distance;
        for(int i=0;i<leaf.size();i++)
        {
            dfs(leaf[i],leaf[i],leaf[i],0);
        }
        return ans.size();
    }
};