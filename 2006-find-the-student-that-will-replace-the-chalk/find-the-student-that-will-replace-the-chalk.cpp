class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for(int i=0; i<chalk.size(); i++){
            sum += chalk[i];
        }
        
        long long temp = -1, ans = 0;
        
        if(sum <= k){
            temp = k % sum;    
        }
        else{
            temp = k;
        }
        
        if(temp == 0)
            return ans;
        
        for(int i=0; i<chalk.size(); i++){
            if(chalk[i] <= temp)
                temp -= chalk[i];
            else
                return i;
        }
        
        return ans;
    }
};