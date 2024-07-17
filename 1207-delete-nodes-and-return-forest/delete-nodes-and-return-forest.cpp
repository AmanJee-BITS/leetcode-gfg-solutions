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
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		if (!root)
			return {};

		unordered_set<int> toDelNodes;
		vector<TreeNode*> result;
        
		for (auto it : to_delete) {
			toDelNodes.insert(it);
		}

		if (toDelNodes.find(root->val) == toDelNodes.end()) {
			result.push_back(root);
		}

		queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        
		while(!pendingNodes.empty()){
			auto front = pendingNodes.front();
			pendingNodes.pop();

			if(front->left) 
                pendingNodes.push(front->left);
            
			if(front->right) 
                pendingNodes.push(front->right);

			if(front->left && toDelNodes.count(front->left->val)){
				front->left = NULL;
			}
            
			if(front->right && toDelNodes.count(front->right->val)){
				front->right = NULL;
			}

			if(toDelNodes.count(front->val)){
				if(front->left) 
                    result.push_back(front->left);
				if(front->right) 
                    result.push_back(front->right);
			}
		}

		return result;
	}
};