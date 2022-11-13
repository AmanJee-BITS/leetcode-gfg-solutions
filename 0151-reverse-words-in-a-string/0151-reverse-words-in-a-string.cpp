class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string a = "";
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                a.push_back(s[i]);
            }
            else{
                if(a.length() > 0){
                    v.push_back(a);
                    a.clear();
                }
            }
        }
        if(a.length() > 0)
            v.push_back(a);
        
        reverse(v.begin(), v.end());
        string ans = "";
        
        for(int i=0; i<v.size(); i++){
            ans.append(v[i]);
            if(i != (int)v.size() -1)
                ans += ' ';
        }
        
        return ans;
    }
};