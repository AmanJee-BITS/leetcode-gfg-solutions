class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int prev = 0;
        
        for(int i=0; i<bank[0].length(); i++){
            if(bank[0][i] == '1'){
                prev++;
            }
        }
        
        
        for(int i=1; i<bank.size(); i++){
            int temp = 0;
            for(int j=0; j<bank[i].length(); j++){
                if(bank[i][j] == '1'){
                    temp++;
                }
            }
            if(temp !=0){
                count += prev*temp;
                prev = temp;
            }
        }
        
        return count;
    }
};