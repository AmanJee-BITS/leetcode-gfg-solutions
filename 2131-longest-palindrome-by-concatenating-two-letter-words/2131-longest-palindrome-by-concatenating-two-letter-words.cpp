class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count = 0;
        map<string, int> mp;
        mp[words[0]]++;
        
        for(int i=1;i<words.size();i++) {
            string str = "";
            str += words[i][1];
            str += words[i][0];
            if(mp[str]) {
                count += 4;
                mp[str]--;
            }
            else {
                mp[words[i]]++;
            }
        }
        
        for(auto x : mp) {
            if(x.second == 1) {
                string s = x.first;
                if(s[0] == s[1]) {
                    count += 2;
                    break;
                }
            }
        }
        
        return count;
    }
};