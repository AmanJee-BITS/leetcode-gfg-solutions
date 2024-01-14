class Solution {
public:
    bool closeStrings(string w1, string w2) {
        vector<int> ct1(26,0);
        vector<int> ct2(26,0);
        if(w1.size() != w2.size()) return false;
        for(int i=0; i<w1.size(); i++){
            ct1[w1[i]-'a']+=1;
        }

        for(int i=0; i<w2.size(); i++){
            ct2[w2[i]-'a']+=1;
        }

        sort(ct1.begin(), ct1.end());
        sort(ct2.begin(), ct2.end());

        if(set(w1.begin(), w1.end()) != set(w2.begin(), w2.end())) return false;

        for(int i=0; i<26; i++){
            if(ct1[i] != ct2[i]) return false;
        }

        return true;
    }
};