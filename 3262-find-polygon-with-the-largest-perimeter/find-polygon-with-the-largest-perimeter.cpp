class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;

        for(int j=0; j<nums.size(); j++){
            sum += nums[j];
        }

        for(int i=nums.size()-1; i>1; i--){
            if(nums[i]<sum-nums[i]){
                return sum;
            } else {
                sum -= nums[i];
            }
        }
        
        return -1;
    }
};