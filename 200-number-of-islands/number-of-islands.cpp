class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            return;
        }
        
        if(grid[x][y] == '0') return;

        grid[x][y] = '0';

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            dfs(x + dx[i], y+dy[i],  grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j, grid);
                }
            }
        }

        return cnt;
    }
};