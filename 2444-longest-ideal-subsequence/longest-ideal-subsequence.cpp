class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> len(26);

        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a';

            int lo = max(0, val - k);
            int hi = min(25, val + k);

            int maxi = 0;

            for (int j = lo; j <= hi; j++) {
                maxi = max(maxi, len[j]);
            }

            len[val] = maxi + 1;
        }

        int max = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if (len[i] > max)
                max = len[i];
        }

        return max;
    }
};