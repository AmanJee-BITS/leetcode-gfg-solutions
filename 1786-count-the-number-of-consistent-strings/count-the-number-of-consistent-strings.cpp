class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> v(123,0);
        
        for(int i=0; i<allowed.length(); i++){
            v[allowed[i]]++;
        }
        
        int cnt = 0;
        
        for(int i = 0; i<words.size(); i++){
            bool flag = true;
            
            for(int j = 0; j<words[i].length(); j++){
                if(v[words[i][j]] != 1){
                    flag = false;
                    break;
                }
            }
            
            if(flag == true){
                cnt++;
            }
        }
        
        return cnt;
    }
};