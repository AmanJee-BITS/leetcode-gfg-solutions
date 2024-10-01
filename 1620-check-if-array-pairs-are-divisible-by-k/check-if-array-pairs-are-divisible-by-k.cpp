class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        
        for (int i = 0; i < arr.size(); i++) 
            freq[((arr[i] % k) + k) % k]++;
        
        for(auto item : freq){
            if(item.first == (k - item.first) % k && freq[item.first] % 2)
                return false;
            if(freq[item.first] != freq[(k - item.first) % k])
                return false;
        }
        return true;
    }
};