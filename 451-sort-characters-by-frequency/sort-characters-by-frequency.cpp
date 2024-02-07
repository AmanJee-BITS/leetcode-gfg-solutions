class Solution {
public:
    string frequencySort(string s) {

        unordered_map< char, int > m1;
        for (char ch : s) {
            m1[ch]++;
        }

        multimap< int, char, greater <int> > m2;
        for(const auto& p : m1) {
            m2.insert(make_pair(p.second, p.first));
        }

        string res;
        res.reserve(s.size());
        for(const auto& p : m2) {
            res += string(p.first, p.second);
        }
        return res;
    }
};