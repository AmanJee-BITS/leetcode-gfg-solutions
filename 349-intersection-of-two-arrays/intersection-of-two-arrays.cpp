class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> mp;

        for(int n : nums1){
            mp[n]++;
        }

        for(int n : nums2){
            if(mp.find(n)!= mp.end() and mp[n]>0) {
                mp[n] = 0;
                ans.push_back(n);
            }
        }
        
        return ans;
    }
};