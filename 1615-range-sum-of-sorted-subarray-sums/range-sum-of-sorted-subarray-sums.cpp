class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
     
        vector<int> s;
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];
                s.push_back(sum);
            }
        }
        
        sort(s.begin(),s.end());
        
        int ans = 0;
        int m = 1000000007;
        for(int i = left-1; i<= right-1; i++){
            ans += s[i];
            ans %= m; 
        }
        
        return ans;
    }
};