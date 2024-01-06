class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    int pick(int target) {
        int n = nums.size();
        int idx = rand()%n;

        if(nums[idx]==target)
            return idx;
        else{
            while(nums[idx]!=target){
                idx=rand()%n;
            }
            return idx;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */