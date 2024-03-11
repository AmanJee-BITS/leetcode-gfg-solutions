class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;

        for(char c:s){
            mp[c]++;
        }

        string ans = "";

        for(char c:order){
            if(mp.find(c)!=mp.end()){
                while(mp[c] > 0){
                    ans += c;
                    mp[c]--;
                }
            }
        }

        for(auto m:mp){
            while(m.second > 0){
                ans += m.first;
                m.second--;
            }
        }

        return ans;
    }
};