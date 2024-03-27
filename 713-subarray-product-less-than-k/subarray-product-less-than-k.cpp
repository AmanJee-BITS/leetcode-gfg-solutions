class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {  
        int count=0,start=0,end=0,product=1;
        for(int end=0;end<nums.size();end++)
        {
            product=product*nums[end];
            while(start < end && product >= k)
            {
                product=product/nums[start++];
            }
            if(product < k)
            {
                int len=(end-start)+1;
                count+=len;
            }
        }
        return count;
    }
};