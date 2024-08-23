class Solution {
public:
    int findComplement(int num) {
        int p = 0;
        int i = 0;
        
        while(num){
            int rem = num % 2;
            rem ^= 1;
            p = p + rem * pow(2,i);
            i++;
            num /= 2;
        }
        return p;
    }
};