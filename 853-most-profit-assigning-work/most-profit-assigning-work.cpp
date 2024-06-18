class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        const int n = profit.size(), m = worker.size();

        vector<pair<int, int>> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = {difficulty[i], profit[i]};
        }

        sort(dp.begin(), dp.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, idx = 0, bestProfit = 0;

        for (int i = 0; i < m; i++) {
            while (idx < n && worker[i] >= dp[idx].first) {
                bestProfit = max(bestProfit, dp[idx].second);
                idx++;
            }
            maxProfit += bestProfit;
        }

        return maxProfit;
    }
};