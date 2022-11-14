class Solution {
public:
	int count = 0;
    
	void DFS(vector<vector<int>>& stones, vector<bool>& visited, int start, int& count){
		visited[start] = true;
		vector<int> start_vector = stones[start];
		
        for (int i = 0; i < stones.size(); i++){
		//checking if the node has node has not been visited and it is in same row or column
			if (visited[i] == false && (start_vector[0] == stones[i][0] || start_vector[1] == stones[i][1])){
				count++;
				DFS(stones, visited, i, count);
			} 
		}
	}
    
	int removeStones(vector<vector<int>>& stones) {
		int n = stones.size();
		vector<bool> visited(n, false);  // checking for visited components

		for (int i = 0; i<n; i++){
			//running DFS for every visited component;
			if (visited[i] == 0) DFS(stones, visited, i, count);
		}
		return count;
	}
};