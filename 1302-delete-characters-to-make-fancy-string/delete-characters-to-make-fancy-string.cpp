class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;
        int cnt = 0;
        
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
                cnt++;
            }
            else{
                if(st.top() == s[i]){
                    if(cnt == 2){
                        
                    }
                    else{
                        st.push(s[i]);
                        cnt++;
                    }
                }
                else{
                    st.push(s[i]);
                    cnt = 1;
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};