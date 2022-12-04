class Solution {
public:
    void solve(vector<int>& v1,vector<int>& v2,int& ans) {
        
    }

    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();

        long long sum1 = 0, sum2 = 0;
        for(auto i : nums) sum2+=i;
        
        int minIndex = -1, minDiff = INT_MAX;
        for(int i = 0; i<nums.size();i++) {
            
            sum1+=nums[i];
            sum2-=nums[i];
            int avg1 = sum1/(i+1);
            int avg2 = 0;
            if(i != n-1) avg2 = sum2/(n-i-1);

            int diff = abs(avg1 - avg2);

            if(minDiff > diff) {
                minDiff = diff;
                minIndex = i;
            }
        }
        return minIndex;
    }
};