class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        
        for(int i = 0; i<logs.size(); i++){
            if(logs[i] != "../" and logs[i] != "./"){
                count++;
            }
            if(logs[i] == "../" and count!=0){
                count--;
            }
            if(logs[i] == "./"){
            }
        }
        
        return count;
    }
};