class Solution {
public:
    int i = 0;
    int calculate(string s) {
        int ans = 0, sign = 1;
        
        for(i; i<s.size(); i++){
            if(s[i] == '-'){
                sign = -1;
            }
            else if(s[i] == ')'){
                return ans;
            }
            else if(s[i] == '('){
                i++;
                ans += (sign) * calculate(s);
                sign = 1;
            }
            else if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                ans += (sign)*(num);
                sign = 1;
                i--;
            } else{
                continue;
            }
        }
        return ans;
    }
};