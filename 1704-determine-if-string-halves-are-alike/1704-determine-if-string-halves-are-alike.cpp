class Solution {
public:
    bool isVow(char s){
        string st = "aeiouAEIOU";
        
        for(int j=0; j<st.length(); j++){
            if(s == st[j])
                return true;
        }
        
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int l = 0, h = 0;
        int len = s.length();
        
        for(int i=0; i<len/2; i++){
            if(isVow(s[i]))
                l++;
        }
        
        for(int i=len/2; i<len; i++){
            if(isVow(s[i]))
                h++;
        }
        
        if(l == h)
            return true;
        
        return false;
    }
};