class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        
        for(int i=1; i<s.length(); i++){
            if(s[i] == s[i-1]){
                int num = min(cost[i], cost[i-1]);
                ans += min(cost[i], cost[i-1]);
                cost[i] = max(cost[i], cost[i-1]);
            }
        }
        
        return ans;
    }
};