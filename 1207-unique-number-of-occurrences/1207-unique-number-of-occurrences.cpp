class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>a;
        for(int x : arr){
            a[x]++;
        }
        
        unordered_set<int> b;
        for(auto it = a.begin(); it != a.end(); ++it){
            b.insert(it->second);
        }
        
        if(b.size() == a.size()) 
            return true;
        else 
            return false;
    }
};