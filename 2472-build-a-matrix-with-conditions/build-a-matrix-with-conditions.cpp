class Solution {
    vector<int> topologicalSort(vector<vector<int>>& edges, int n) {
        vector<int> order, indegree(n + 1), adjList[n + 1];
        queue<int> Queue;

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (!indegree[i])
                Queue.push(i);
        }

        while (!Queue.empty()) {
            int curr = Queue.front();
            Queue.pop();
            order.push_back(curr);
            for (int next : adjList[curr]) {
                indegree[next]--;
                if (!indegree[next])
                    Queue.push(next);
            }
            n--;
        }

        if(n) return {};

        return order;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> rowTopoOrder = topologicalSort(rowConditions, k);
        vector<int> colTopoOrder = topologicalSort(colConditions, k);

        if (rowTopoOrder.empty() || colTopoOrder.empty())
            return {};
    
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rowTopoOrder[i] == colTopoOrder[j])
                    ans[i][j] = rowTopoOrder[i];
            }
        }

        return ans;
    }
};