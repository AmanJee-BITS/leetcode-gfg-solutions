class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0; i<=sqrt(c); i++) {
            long long t = sqrt(c-i*i);
            if(t*t == c-(i*i)) 
                return true;
        }
        return false;
    }
};