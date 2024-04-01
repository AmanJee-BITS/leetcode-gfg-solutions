class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == ' ' and cnt != 0)
                break;
            else if(s[i] == ' ' and cnt == 0){
                
            }
            else
                cnt++;
        }
        
        return cnt;
    }
};