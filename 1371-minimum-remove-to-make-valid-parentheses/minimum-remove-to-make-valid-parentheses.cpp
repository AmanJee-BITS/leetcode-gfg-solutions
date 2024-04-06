class Solution {
public:
    string minRemoveToMakeValid(string s) {
        deque<pair<char, int>> q;
        int idx=0, len = s.length();
        vector<bool> v(len+1, false);
        
        for(char c:s){
            idx++;
            if(c =='(' or c == ')'){
                if(q.empty()){
                    q.push_front({c, idx});
                }
                else if(c==')' and q.front().first == '('){
                    v[idx] = true;
                    v[q.front().second] = true;
                    q.pop_front();
                }
                else{
                    q.push_front({c, idx});
                }
            }
        }
        
        string ans="";
        idx=0;
        
        for(char c:s){
            idx++;
            if(c =='(' or c == ')'){
                if(v[idx]==true){
                    ans += c;
                }
            }
            else{
                ans += c;
            }
        }
        return ans;
    }
};