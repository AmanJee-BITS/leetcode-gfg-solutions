class Solution {
public:
    static int minGroups(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> temp;
        temp.reserve(n * 2);

        for (auto& I : intervals) {
            int x = I[0], y = I[1] + 1;
            temp.push_back((x << 1) + 1);
            temp.push_back(y << 1);
        }
        
        sort(temp.begin(), temp.end());

        int cnt = 0, x = 0;
        
        for (int z : temp) {
            x += (z & 1) ? 1 : -1;
            cnt = max(cnt, x);
        }

        return cnt;
    }
};