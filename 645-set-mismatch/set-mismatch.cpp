class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<int> v(len+1, 0);
        
        for(int i=0; i<len; i++){
            v[nums[i]]++;
        }
        
        vector<int> ans;
        int req = 0;
        
        for(int i = 1; i<v.size(); i++){
            if(v[i] == 2)
                ans.push_back(i);
            if(v[i] == 0)
                req = i;
        }
        ans.push_back(req);
        return ans;
    }
};