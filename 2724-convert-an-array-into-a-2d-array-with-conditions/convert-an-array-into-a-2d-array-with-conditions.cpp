class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int maxCount = 0;

        for(auto x:nums){
           mp[x]++;
           maxCount = max(maxCount, mp[x]);
        }

        vector<vector<int>> ans(maxCount);

        for(auto m:mp){
            int i = 0;
            while(m.second--){
                ans[i++].push_back(m.first);
            }
        }

        return ans;
    }
};