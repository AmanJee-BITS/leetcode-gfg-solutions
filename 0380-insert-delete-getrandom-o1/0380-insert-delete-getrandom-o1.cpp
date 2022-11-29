class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> s;
    vector<int> v;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val)==s.end()){
            v.push_back(val);
            s[val] = v.size()-1;
            return true;
        }
        return false;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto tmp = s.find(val);
        if(tmp!=s.end()){
            int idx = s[val];
            v[idx] = v.back();
            s[v.back()] = idx;
            v.pop_back();
            s.erase(tmp);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */