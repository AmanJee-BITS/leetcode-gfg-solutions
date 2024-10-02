class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> m;
        int i = 1;
        int j = 0;

        for (auto x : s)
            m[x] = i++;
        for (auto x : arr)
            arr[j++] = m[x];

        return arr;
    }
};