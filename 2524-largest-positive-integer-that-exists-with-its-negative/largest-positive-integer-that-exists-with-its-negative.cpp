class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> vp(1001,0), vn(1001,0);
        
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                nums[i] *= -1;
                vn[nums[i]]++;
            }else{
                vp[nums[i]]++;
            }
        }
        
        int ans = -1;
        for(int i=0; i<vp.size(); i++){
            if(vp[i] > 0 and vn[i] > 0){
                ans = i;
            }
        }
        
        return ans;
    }
};