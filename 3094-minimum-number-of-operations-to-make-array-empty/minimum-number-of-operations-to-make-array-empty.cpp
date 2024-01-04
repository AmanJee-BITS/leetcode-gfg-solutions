class Solution {
public: 
    int minOperations(vector < int > & nums) {
        map <int,int> mp;
        int ans = 0;
        
        for (int x: nums) {
            mp[x]++;
        }

        for (auto m: mp) {
            int y = m.second;
            if(y==1)
                return -1;

            ans += y/3;

            if(y%3)
                ans++;
        }
        return ans;
    }
};