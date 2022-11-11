class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        
        int num = nums[0];
        int cnt = 1;
        vector<int>::iterator it;
        
        for(auto it = nums.begin()+1; it != nums.end(); ++it){
            if(*it == num){
                nums.erase(it--);
            }
            else{
                num = *it;
                cnt++;
            }
        }
        cout<<cnt;
        return cnt;
    }
};