class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currNeg = nums[0]; // store minimum product till now
        int currPos = nums[0]; // store maximum product till now
        int pro = nums[0];

        for (int n=1; n<nums.size(); n++) {
            int tempPro = max({nums[n], nums[n] * currPos, nums[n] * currNeg});
            currNeg = min({nums[n], nums[n] * currPos, nums[n] * currNeg});
            currPos = tempPro;
            pro = max(pro, currPos);
        }

        return pro;
    }
};