//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, int parent){
        vis[node] = 1;
        
        for(int n:adj[node]){
            if(!vis[n]){
             if(dfs(n, adj, vis, node)) return true;   
            }
            else if(vis[n] && n!=parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1,0);
        
        for(int node = 0; node<V; node++){
            if(!vis[node]){
                if(dfs(node, adj, vis, -1)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends