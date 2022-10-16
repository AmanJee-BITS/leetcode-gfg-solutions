class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        string temp = "";
        
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
            temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            nums[i] = stoi(temp);
            s.insert(nums[i]);
        }
        
        return s.size();
    }
};