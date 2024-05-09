class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans=0, temp=0;
        
        for(int i=0; i<happiness.size(); i++){
            if(temp==k) break;
            ans += max(0, (int)(happiness[i] - temp));
            temp++;
        }
                
        return ans;
    }
};