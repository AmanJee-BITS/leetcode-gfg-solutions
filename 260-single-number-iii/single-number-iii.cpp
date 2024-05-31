class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        stack<int> v;
        int pos = 1;
        bool flag = false;
        
        if(nums[0] == nums[1]){
            flag = true;
            v.push(nums[1]);
            pos++;
        }
        else{
            v.push(nums[0]);
        }
        
        for(int i = pos; i<nums.size(); i++){
            if(nums[i] != v.top()){
                v.push(nums[i]);
            }
            else{
                v.pop();
            }
        }
        vector<int> s;
        
        while(!v.empty()){
            int num = v.top();
            s.push_back(num);
            v.pop();
        }
        reverse(s.begin(), s.end());
        
        if(flag == true){
            s.erase(s.begin());
        }
        
        return s;
    }
};