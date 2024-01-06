class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        map<pair<int,int>,int> mp;
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            mp[{endTime[i],startTime[i]}]=profit[i];//mapping the profit with their corresponding time interval
            arr.push_back({endTime[i],startTime[i]});//vector of pairs with endtime and starttime
        }

        sort(arr.begin(),arr.end());//sorting time intervals according to endtime
        sort(endTime.begin(),endTime.end());//sorting endtime 

        vector<int>dp(n,0);//dp[i] represents maximum profit upto index i
        dp[0] = mp[arr[0]];

        for(int i=1;i<n;i++){
            auto j = upper_bound(endTime.begin(),endTime.end(),arr[i].second)-endTime.begin();// calculating upperbound  to get index j of nonoverlapping subinterval  with interval i; 
            if(j == 0){
                dp[i] = max(dp[i-1],mp[arr[i]]);// nonoverlapping subinterval is not present
            }
            else{
                dp[i] = max(dp[i-1],dp[j-1]+mp[arr[i]]);
            }
        }
        return dp[n-1];
    }
};