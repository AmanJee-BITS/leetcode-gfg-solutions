class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        vector<int> charcnt(26, 0);

        for (auto ch : tasks) {
            charcnt[ch - 'A']++;
        }

        sort(charcnt.begin(), charcnt.end(), greater<int>());

        int maxfrquencychar = charcnt[0] - 1;
        int idle_slot = maxfrquencychar * n;

        for (int i = 1; i < 26; i++) {
            idle_slot -= min(charcnt[i], maxfrquencychar);
        }
        
        int ans = idle_slot > 0 ? idle_slot + tasks.size() : tasks.size();
        return ans;
    }
};