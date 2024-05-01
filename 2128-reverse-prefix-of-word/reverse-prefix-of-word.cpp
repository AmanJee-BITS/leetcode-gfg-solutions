class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        bool flag = false;
        
        for(auto c : word){
            i++;
            if(c == ch){
                flag = true;
                break;
            }
        }
        
        if(!flag)
            return word;
        
        for(int j=0; j<i/2; j++){
            swap(word[j],  word[i-j-1]);
        }
        
        return word;
    }
};