class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);
        
        int low_len = l.length(), high_len = h.length();
        vector<int> ans;
        string temp = "";
        
        while(low_len <= high_len){
            for(int i=0 ;i<s.length(); i++){
                temp = s.substr(i, low_len);
                
                if((int)temp.length() == low_len){                
                    if(stoi(temp) >= low and stoi(temp) <= high){
                        ans.push_back(stoi(temp));
                    }
                }
            }
            low_len++;
        }
        
        return ans;
    }
};