class Solution {
public:
    int solve(vector<int>& nums, int k){
        int i=0,res=0;
        unordered_map<int,int> m;

        for(int j=0;j<nums.size();j++){
            if(!m[nums[j]]++)
                k--;
            
            while(k<0){
                if(!--m[nums[i]])
                    k++;
                i++;
            }
            res += j-i+1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k){
        return solve(nums,k)-solve(nums,k-1);
    }
};
