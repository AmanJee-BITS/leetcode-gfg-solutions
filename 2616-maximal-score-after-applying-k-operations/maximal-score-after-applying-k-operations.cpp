class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto x : nums){
            pq.push(x);
        }
        
        long long ans=0, temp=0;
        while(k--){
            temp = pq.top();
            ans += temp;
            temp = temp%3 == 0 ? temp/3 : 1+temp/3;
            pq.push(temp);
            pq.pop();
        }
        
        return ans;
    }
};