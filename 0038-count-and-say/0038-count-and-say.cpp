class Solution {
public:
    string countAndSay(int n) {
        //Base cases
        if(n==1) {return "1";}
        if(n==2) {return "11";}

        //Initialize res
        string res = "11";

        for(int i=3; i<=n; i++){
            string curr = "";
            for(int j=0; j<res.length();j++){
                int letter_counter = 1;
                while(j+1<res.size() && res[j]==res[j+1]){
                    letter_counter++;
                    j++;
                }
                curr += to_string(letter_counter) + res[j];
            }
            res = curr;
        }
        return res; 
    }
};