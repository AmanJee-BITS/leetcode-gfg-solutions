class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int mx=0,cnt=0;
        
        for(int x:nums){
            mp[x]++;
            mx = mx > mp[x] ? mx : mp[x];
        }
        
        for(auto m:mp){
            if(m.second == mx) cnt++;
        }
        
        return cnt*mx;
    }
};