class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, set<pair<int,int>> &st, vector<bool> &vis, int& no) {
        no++;
        vis[node] = true;

        for(int i = 0; i < adj[node].size(); i++) {
            st.insert({min(node, adj[node][i]), max(node, adj[node][i])});
            if(!vis[adj[node][i]]) {
                dfs(adj, adj[node][i], st, vis, no);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(int i = 0; i < e.size(); i++) {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int no = 0;
                set<pair<int,int>> st;
                dfs(adj, i, st, vis, no);
                if(st.size() == (no*(no-1))/2) ans++;
            }
        }
        return ans;
    }
};