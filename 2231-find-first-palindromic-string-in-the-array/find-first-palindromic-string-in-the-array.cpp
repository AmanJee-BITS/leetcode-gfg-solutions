class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string temp = "";
        
        for(auto word : words){
            temp = word;
            reverse(word.begin(), word.end());
            if(temp == word)
                return word;
        }
        
        return "";
    }
};