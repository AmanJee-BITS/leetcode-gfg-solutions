class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return lowerBound(nums, upper) - lowerBound(nums, lower - 1);
    }

private:
    long long lowerBound(vector<int>& nums, int bound) {
        long long res = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] <= bound) {
                res += j - i;
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};