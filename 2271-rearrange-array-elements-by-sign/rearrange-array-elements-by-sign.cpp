class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos, neg;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)
                pos.push(nums[i]);
            else
                neg.push(nums[i]);
        }
        
        nums.clear();
        
        while(!pos.empty()){
            nums.push_back(pos.front());
            nums.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        
        return nums;
    }
};