class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> m;
        for (auto n : hand) {
            m[n]++;
        }

        queue<pair<int, int>> start;
        int len = 0, last = m.begin()->first - 1;
        
        for (auto p : m) {
            if (len > 0 && (p.first - last != 1 || p.second < len))
                return false;
            if (p.second > len) {
                start.push(pair<int, int>(p.first, p.second - len));
                len = p.second;
            }
            if (!start.empty() && p.first - start.front().first + 1 == W) {
                len -= start.front().second;
                start.pop();
            }
            last = p.first;
        }
        return start.empty() && len == 0;
    }
};