class Solution {
public:
    int maxDepth(string s) {
        stack <char> a;
        int count = 0;
        int temp = 0;
        int depth = 0;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                a.push(s[i]);
                temp++;
                
                if(temp > 1){
                    count++;;
                }
                else{
                    count = temp;
                }
            }
            
            else if(s[i] == ')' and a.top() == '('){
                a.pop();
                temp--;
                depth = max(depth, count);
                count--;
            }
        }
        return depth;
        
    }
};