class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int sqrtNum = sqrt(sum);

        return sqrtNum * sqrtNum == sum ? sqrtNum : -1;
    }
};