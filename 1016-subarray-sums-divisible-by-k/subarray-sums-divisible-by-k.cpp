class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int i=0;
        int rem = 0;
        int sum = 0;
        
        map<int, int> m;       
        
        while(i<A.size()){
            sum += A[i];
            rem = sum % k;
            
            if(rem < 0)
                rem += k;
            
            m[rem]++;
            i++;
        }
        
        int cnt = m[0];
        for(auto it = m.begin(); it!= m.end(); it++){
            int val = it->second;
            cnt += (val*(val-1))/2;
        }
        return cnt;
    }
};