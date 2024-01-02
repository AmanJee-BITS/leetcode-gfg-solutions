class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;

        for(auto x:nums){
           mp[x]++;
        }

        int maxCount = 0;

        for(auto m:mp){
            maxCount = max(maxCount, m.second);
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