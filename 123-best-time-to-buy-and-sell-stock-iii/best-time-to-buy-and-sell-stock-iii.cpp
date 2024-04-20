class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price1 = INT_MAX, min_price2 = INT_MAX;
        int profit1 = 0, profit2 = 0;

        for (int x : prices) {
            min_price1 = min(min_price1, x);
            profit1 = max(profit1, x - min_price1);
            min_price2 = min(min_price2, x - profit1);
            profit2 = max(profit2, x - min_price2);
        }

        return profit2;
    }
};