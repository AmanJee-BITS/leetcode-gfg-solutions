class Solution {
    int dp[38]={0};

public:
    int tribonacci(int n) {
        if(n == 2 or n == 1)
            return 1;

        if(n<=0)
            return 0;
        
        if(dp[n])
            return dp[n];
        
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};