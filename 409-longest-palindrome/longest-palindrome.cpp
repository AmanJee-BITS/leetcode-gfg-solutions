class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(123, 0);

        for (int i = 0; i < s.length(); i++) {
            v[s[i]]++;
        }

        int last = 0, sum = 0;
        bool flag = false;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] % 2 == 0 and v[i] != 0) {
                sum += v[i];
            } else if (v[i] % 2 != 0 and v[i] != 0) {
                flag = true;
                sum += v[i] - 1;
            }
        }

        return flag ? sum + 1 : sum;
    }
};