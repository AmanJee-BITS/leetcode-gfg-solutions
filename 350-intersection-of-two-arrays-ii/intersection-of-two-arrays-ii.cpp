class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0, j = 0;
        vector<int> ret;

        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ret;
    }
};