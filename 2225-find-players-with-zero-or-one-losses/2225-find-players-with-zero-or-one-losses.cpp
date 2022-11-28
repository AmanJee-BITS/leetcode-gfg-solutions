class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<pair<bool, int>> v(100001);
        
        for(int i=0; i<matches.size(); i++){
            v[matches[i][0]].first = true;
            v[matches[i][1]].first = true;
            v[matches[i][1]].second++;
        }
        
        vector<vector<int>> ans(2);
        
        for(int i=0; i<v.size(); i++){
            if(v[i].first){
                if(v[i].second == 0){
                    ans[0].push_back(i);
                }

                else if(v[i].second == 1){
                    ans[1].push_back(i);
                }
            }
        }
        
        return ans;
    }
};