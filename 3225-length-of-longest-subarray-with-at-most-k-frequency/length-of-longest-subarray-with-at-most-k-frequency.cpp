class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mp;

        int i = 0, j = 0, len = nums.size();
        int ans = 0;

        while (i <= j and j < len) {
            if (mp.find(nums[j]) == mp.end() or mp[nums[j]] < k) {
                mp[nums[j]]++;
                j++;
            } else {
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i);
        }

        return ans;
    }
};