class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), block(9);
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char ch = board[r][c];
                if(ch == '.')continue;
                if(! row[r].insert(ch).second)return false;
                if(! col[c].insert(ch).second)return false;
                if(!block[r/3*3+c/3].insert(ch).second)return false;
            }
        }
        return true;
    }
};