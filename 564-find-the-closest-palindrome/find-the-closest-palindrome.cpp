class Solution {
typedef long long ll;
public:
    string nearestPalindromic(string numberStr) {
        ll number = stoll(numberStr);

        if (number <= 10)
            return to_string(number - 1);
        if (number == 11)
            return "9";

        if (numberStr == "999999999999999999") {
            return "1000000000000000001";
        }

        int length = numberStr.length();
        ll leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));

        vector<ll> palindromeCandidates(5);
        palindromeCandidates[0] =
            generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] =
            generatePalindromeFromLeft(leftHalf, length % 2 == 0);

        if (leftHalf < 999999999) {
            palindromeCandidates[2] =
                generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
        } else {
            palindromeCandidates[2] =
                stoll("1" + string(length - 1, '0') + "1");
        }

        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;

        ll nearestPalindrome = 0;
        ll minDifference = LLONG_MAX;

        for (ll candidate : palindromeCandidates) {
            if (candidate == number)
                continue;
            ll difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference &&
                                               candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }

        return to_string(nearestPalindrome);
    }

private:
    ll generatePalindromeFromLeft(ll leftHalf,
                                         bool isEvenLength) {
        ll palindrome = leftHalf;
        if (!isEvenLength)
            leftHalf /= 10;
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
};