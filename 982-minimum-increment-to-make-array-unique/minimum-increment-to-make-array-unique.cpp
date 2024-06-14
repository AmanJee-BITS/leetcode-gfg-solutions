class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int cnt = 0;
        sort(A.begin(), A.end());
        
        for(int i=1; i<A.size(); i++){
            if(A[i] <= A[i-1]){
                cnt += A[i-1]- A[i] +1;
                A[i] = A[i-1] + 1;
            }
        }
        
        return cnt;
    }
};