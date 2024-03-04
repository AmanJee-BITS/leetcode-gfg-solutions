class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(), t.end());
        
        int i = 0, j = t.size()-1;
        int score = 0, res = 0;
        
        while (i<=j) {
            if (p>=t[i]) {
                score++;
                res = max(res, score);
                p-=t[i];
                i++;
            } else {
                if (score && t[j] > t[i]) {
                    p+=t[j];
                    score--;
                    j--;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};