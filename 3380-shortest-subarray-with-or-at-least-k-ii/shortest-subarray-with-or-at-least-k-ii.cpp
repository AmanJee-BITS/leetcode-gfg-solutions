class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int z = *max_element(nums.begin(), nums.end());

        if (z >= k)
            return 1;

        int ans = INT_MAX, x = nums[0], i = 0, j = 1;

        while (j < n) {
            x |= nums[j];
            if (x < k) {
                j++;
            } else {
                ans = min(ans, j - i + 1);
                while (i < n && i <= j && x >= k) {
                    ans = min(ans, j - i + 1);

                    if (nums[i] == nums[i + 1]) {
                        i++;
                    } else {
                        i++;
                        x = nums[i];
                        for (int t = i + 1; t <= j; t++) {
                            x |= nums[t];
                        }
                    }
                }
                j++;
            }
        }

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};