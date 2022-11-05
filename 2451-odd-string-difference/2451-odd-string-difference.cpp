class Solution {
public:
    vector<int> findDiff(string s){
        vector<int> v;
        for(int i=1; i<s.size(); i++){
            v.push_back(s[i]-s[i-1]);
        }
        return v;
    }
    
    string oddString(vector<string>& words) {
        vector<vector<int>> diff;
        vector<int> v;
        
        for(string s:words){
            v = findDiff(s);
            diff.push_back(v);
        }
        
        map<vector<int>, int> mp;
                
        for(int i=0; i<diff.size(); i++){
            mp[diff[i]]++;
        }
        
        vector<int> oddDiff;
        for(auto m:mp){
            if(m.second == 1){
                oddDiff = m.first;
            }
        }
        
        int pos =0;
        for(int i=0 ; i<diff.size(); i++){
            if(diff[i] == oddDiff){
                pos = i;
                break;
            }
        }
        
        return words[pos];
    }
};