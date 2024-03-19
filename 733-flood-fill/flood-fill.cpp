class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int& colorToChange, int& color) {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] == color || image[r][c] != colorToChange) {
            return;
        }

        image[r][c] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            dfs(image, r + dr[i], c + dc[i], colorToChange, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int colorToChange = image[sr][sc];

        dfs(image, sr, sc, colorToChange, color);

        return image;
    }
};