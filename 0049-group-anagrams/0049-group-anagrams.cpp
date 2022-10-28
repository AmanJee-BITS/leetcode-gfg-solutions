class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> store;
        
        for(auto s:strs){
            string now = s;
            sort(s.begin(),s.end());
            store[s].push_back(now);
        }
        
        vector<vector<string>> ans;
        
        for(auto i:store)
            ans.push_back(i.second);
        
        return ans;
    }
};