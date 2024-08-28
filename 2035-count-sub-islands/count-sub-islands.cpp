class Solution {
public:
    vector<pair<int, int>> v; //{(0,1), (0, 0), (0,2),...}
    
    void dfs(vector<vector<int>> &grid2, int x, int y){
        if(x < 0 or y < 0 or x >= grid2.size() or y>= grid2[0].size() or grid2[x][y] == 0)
            return;
        
        grid2[x][y] = 0;
        v.push_back({x, y});
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            dfs(grid2, x+dx[i], y+dy[i]);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j] == 1){
                    dfs(grid2, i, j);
                }
                
                int flag = 0;
                for(int k =0; k<v.size(); k++){
                    if(grid1[v[k].first][v[k].second] == 1){
                        flag++;
                    }
                }
                if(v.size() != 0 && flag == v.size())
                    cnt++;
                
                v.clear();
            }
        }
        return cnt;
    }
};