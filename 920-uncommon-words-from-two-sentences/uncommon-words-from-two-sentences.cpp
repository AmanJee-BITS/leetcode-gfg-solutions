class Solution {
public:
    vector<string> toStr(string s){
        vector<string> v;
        string st = "";
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' ')
                st += s[i];
            else{
                v.push_back(st);
                st = "";
            }
        }
        v.push_back(st);
        return v;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> a = toStr(A);
        vector<string> b = toStr(B);
        
        map<string, int> mp;
        
        if(A.length() != 0){
            for(int i=0; i<a.size(); i++){
                mp[a[i]]++;
            }
        }
        
        if(B.length() != 0){
            for(int j=0; j<b.size(); j++){
                mp[b[j]]++;
            }
        }
        
        vector<string> ans;
        for(auto m : mp){
            if(m.second == 1)
                ans.push_back(m.first);
        }
        
        return ans;
    }
};