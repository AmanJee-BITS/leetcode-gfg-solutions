class Solution {
public:
    void safe(int n, int x, int y, vector<vector<int>>& grid){
        if(x < 0 or y < 0 or x >= grid.size() or  y >= grid[0].size() or grid[x][y] != n)
            return;
        
        grid[x][y] = -1;
        
        safe(n, x+1, y+1, grid);
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            safe(grid[i][0], i, 0, grid);
        }
        
        for(int j=1; j<grid[0].size(); j++){
            safe(grid[0][j], 0, j, grid);
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != -1)
                    return false;
            }
        }
        return true;
    }
};