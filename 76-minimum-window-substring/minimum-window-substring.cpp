class Solution {
public:
    string minWindow(string s, string t) {
        int s_len=s.length();
        int t_len=t.length();
        
        vector<int> freq_t(256,0);
        vector<int> freq_s(256,0);
        
        for(int i=0;i<t_len;i++)
            freq_t[t[i]]++;
        
        int win_left=0;               
        int ans=INT_MAX,ans_left;
        int count=0;                 
        
        for(int i=0;i<s_len;i++){
            if(freq_t[s[i]]>0 && freq_t[s[i]]>freq_s[s[i]])
                count++;
            freq_s[s[i]]++;
            if(count==t_len){ 
                while(win_left<i &&         
                      (freq_t[s[win_left]]<freq_s[s[win_left]] || freq_t[s[win_left]]==0)){
                    
                    if(freq_t[s[win_left]]<freq_s[s[win_left]])
                        freq_s[s[win_left]]--;
                    win_left++;
                }
                if(ans>(i-win_left+1)){
                    ans=(i-win_left+1);
                    ans_left=win_left;    
                }
            }
        }
        
        if(ans==INT_MAX)
            return "";
        return s.substr(ans_left,ans);
    }
};