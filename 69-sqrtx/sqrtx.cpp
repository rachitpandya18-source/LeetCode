class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(mid * mid <= (long long)x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};