class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;        
        map<int, int> m;
        
        for(auto val : nums){
            m[val]++;
        }
        
        for(int i=0; i<m.size(); i++){
            if(m[i] == 2)
                v.push_back(i);
        }
        
        return v;
    }
};