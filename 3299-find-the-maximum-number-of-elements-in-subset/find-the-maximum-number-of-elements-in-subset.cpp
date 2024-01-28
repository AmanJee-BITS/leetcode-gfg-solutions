class Solution {
public: 
    bool isSquare(int n) {
        if (n < 0)
            return false;
        int root = sqrt(n);
        return (root*root== n);
    }
    
    int maximumLength(vector<int>& nums) {
        map<int,int> map; 
        
        for(int num : nums){
            map[num]++; 
        } 
        
        // For handling sequence of 1 1 1 1 1 ....
        int one = map[1]; 
        int ans = one%2 ? one : max(0 , one-1);  
         
        for(int num : nums){  
            int cnt = 1; 
            while(isSquare(num) and num!=1){
                int root = sqrt(num); 
                if(map[root]<2)
                    break; 
                else 
                    cnt+=2; 
                num = root; 
            } 
            ans = max(ans , cnt); 
        }
        return ans;
    }
};