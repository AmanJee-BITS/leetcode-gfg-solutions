class Solution {
public:
string makeGood(string s) {
        stack<char> st;
        string ans;

        for(int i=0;i<s.size();++i){
          if(!st.empty() && abs(st.top()-s[i])==32)
              st.pop();
          else st.push(s[i]);
        }

        while(!st.empty()) ans=st.top()+ans, st.pop();
        return ans;
    }
};