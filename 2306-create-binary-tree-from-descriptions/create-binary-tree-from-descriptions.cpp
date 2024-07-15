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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> children;
        
        for (auto &d: descriptions) {
            children.insert(d[1]);
            auto it_p = m.find(d[0]), it_c = m.find(d[1]);
            if (it_p == end(m))
                it_p = m.insert({d[0], new TreeNode(d[0]) }).first;
            if (it_c == end(m))
                it_c = m.insert({d[1], new TreeNode(d[1]) }).first;
            if (d[2])
                it_p->second->left = it_c->second;
            else
                it_p->second->right = it_c->second;
        }
        
        for (auto &p : m)
            if (children.find(p.first) == end(children))
                return p.second;
        
        return nullptr;
    }
};