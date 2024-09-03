class Solution {
public:
    int getLucky(string s, int k) {
        string st = "";
        
        for(auto c : s){
            st += to_string((c - 'a') + 1 );
        }
        cout<<st<<endl;
        int ans = 0;
        
        while(k--){
            ans = 0;
            for(auto c : st){
                ans += (c - '0');
            }
            st = to_string(ans);
        }
        
        return ans;
    }
};