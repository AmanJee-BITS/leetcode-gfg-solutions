class Solution {
public:
    int maximum69Number(int num) {
        int copy = num;
        for (int i = 1000; i > 0; i /= 10){
            if (copy / i == 6){
                num += 3 * i;
                return num;
            }
            copy -= (copy / i) * i;
        }
        return num;
    }
};