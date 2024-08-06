class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        
        for(auto &s : arr){
            ++mp[s];
        }
        
        int temp = 0;
        string ans = "";
        
        for(auto i : arr){
            if(mp[i] == 1){
                ans = i;
                temp++;
            }
            if(temp == k)
                break;
        }
        if(temp < k)
            ans = "";
        
        return ans;
    }
};