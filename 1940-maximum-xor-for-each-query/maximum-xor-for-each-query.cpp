class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int len = nums.size();
        vector<int> dp(len, 0);
        vector<int> ans;

        dp[0] = nums[0];

        int maxx = pow(2, maximumBit) - 1; // maxx = maximum possible k
        int temp = maxx ^ nums[0]; // If a^b = c, then a = c^b and b = c^a
        ans.push_back(temp);

        for (int i = 1; i < len; i++) {
            dp[i] = dp[i - 1] ^ nums[i];
            temp = maxx ^ dp[i];
            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};