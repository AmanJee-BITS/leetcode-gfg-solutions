class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = 1;
        bool flag = false;
        
        for(int i = nums.size() - 1; i>= 0; i--){
            if(nums[i] >= len){
                flag = true;
                len++;
            }
        }
        
        len--;
        int count = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] >= len)
                count++;
        }
        
        if(count == len)
            return count;
        else
            return -1;        
    }
};