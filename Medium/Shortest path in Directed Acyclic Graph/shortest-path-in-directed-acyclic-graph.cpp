//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> solve(vector<pair<int,int>> adj[], int N){
        queue<int> q;
        q.push(0);
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto node : adj[x]){
                if(dist[node.first] > dist[x] + node.second){
                   dist[node.first] = dist[x] + node.second;
                   q.push(node.first);
                }
            }
        }
        
        for(int x=0; x<N; x++){
            if(dist[x] == 1e9) dist[x] = -1;
        }
        
        return dist;
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        return solve(adj, N);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends