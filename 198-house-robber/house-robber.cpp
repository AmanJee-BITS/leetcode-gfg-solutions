class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> amount(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0;
        
        else if(nums.size()==1)
            return nums[0];
        
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        if(nums[0]>nums[1])
            amount[1] = nums[0];
        
        for(int i = 2; i < nums.size(); i++){
            amount[i] = max(amount[i-1],amount[i-2]+nums[i]);
        }
        return amount.back();
    }
};