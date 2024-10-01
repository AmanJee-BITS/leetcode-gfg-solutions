class CustomStack {
public:
    stack<int> s;
    int cnt = 0;
    
    CustomStack(int maxSize) {
        cnt = maxSize;
    }
    
    void push(int x) {
        if(cnt > 0){
            s.push(x);
            cnt--;
        }
    }
    
    int pop() {
        if(!s.empty()){
            int n = s.top();
            cnt++;
            s.pop();
            return n;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        vector<int> v;
        
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        
        reverse(v.begin(), v.end());
        int len = v.size();
        len = min(k,len);
        
        for(int i=0; i<len; i++){
            v[i] += val;
        }
        
        for(int i=0; i<v.size(); i++){
            s.push(v[i]);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */