class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(int i=0; i< tokens.size(); i++){
            if(tokens[i].size() > 1){
                s.push(stoi(tokens[i]));
            }
            else{
                if(tokens[i][0] == '+'){
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.pop();
                    tokens[i] = to_string(x+y);
                }
                else if(tokens[i][0] == '-'){
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.pop();
                    tokens[i] = to_string(y-x);
                }
                else if(tokens[i][0] == '*'){
                    long long x = s.top();
                    s.pop();
                    long long y = s.top();
                    s.pop();
                    tokens[i] = to_string(x*y);
                }
                else if(tokens[i][0] == '/'){
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.pop();
                    tokens[i] = to_string(y/x);
                }
                s.push(stoll(tokens[i]));
            }    
        }
        
        return s.top();
    }
};