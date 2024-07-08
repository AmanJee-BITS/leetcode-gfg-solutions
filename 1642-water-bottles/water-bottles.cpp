class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0;
        int bBottles = numBottles;
        int left = 0;
        
        while(bBottles > 0){
            sum += min(numExchange, bBottles);
            bBottles = bBottles - numExchange + 1;  
            left = bBottles;
        }
        
        return sum;
    }
};