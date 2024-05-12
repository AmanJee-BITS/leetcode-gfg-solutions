class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> mp;
        int i = 0, ans = 0;

        for (char c : s) {
            mp[c] = i++;
        }

        i = 0;

        for (char c : t) {
            ans += abs(mp[c] - i++);
        }

        return ans;
    }
};