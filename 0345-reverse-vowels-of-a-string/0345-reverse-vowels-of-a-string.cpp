bool isVowel(char c){
    string vow = "aeiouAEIOU";
    for(int i = 0; i<vow.length(); i++){
        if(vow[i] == c)
            return true;
    }
    return false;
}

class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        stack<char> st;
        
        for(int i=0; i<len; i++){
            if(isVowel(s[i]) == true){
                st.push(s[i]);
            }
        }
        
        for(int i=0; i<len; i++){
            if(isVowel(s[i]) == true){
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};