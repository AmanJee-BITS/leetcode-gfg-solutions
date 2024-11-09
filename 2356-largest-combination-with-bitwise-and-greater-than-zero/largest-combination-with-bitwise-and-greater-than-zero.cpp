class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_set = 0;

        for (char b = 0; b < 24; b++) {
            int b_bit_set = 0;
            for (bitset<24> x : candidates) {
                b_bit_set += x[b];
            }
            max_set = max(max_set, b_bit_set);
        }

        return max_set;
    }
};
