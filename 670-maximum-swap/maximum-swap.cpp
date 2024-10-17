class Solution {
public:
    int pow10[9] = {1,      10,      100,      1000,     10000,
                    100000, 1000000, 10000000, 100000000};

    inline int swapInc(int i, int j, vector<char>& digit) {
        if (j == -1)
            return 0;
        return (digit[i] - digit[j]) * (pow10[j] - pow10[i]);
    }

    int maximumSwap(int num) {
        if (num == pow10[8])
            return num;

        vector<char> digit;
        digit.reserve(8);

        int x, d, xD = -1, xIdx = -1, i = -1, j = -1;

        for (x = num, d = 0; x > 0; x /= 10, d++) {
            int z = x % 10;
            digit.push_back(z);
            if (z > xD)
                xD = z, xIdx = d;
            else if (xD > z)
                i = xIdx, j = d;
        }
        
        return num + swapInc(i, j, digit);
    }
};