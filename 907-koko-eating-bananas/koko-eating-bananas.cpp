class Solution {
    bool canEat(vector<int>& piles, long long k, int h, int n) {
        long long totalTime = 0;
        for(int i = 0; i < n; i++) {
            if(piles[i] <= k) totalTime += 1;
            else {
                if(piles[i] % k == 0) totalTime += (piles[i] / k);
                else totalTime += ((piles[i] / k) + 1);
            } 
        }

        return totalTime <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = LONG_MIN;
        int n = piles.size();

        for(int i = 0; i < n; i++) maxi = max(maxi, piles[i]);

        long long low = 1, high = maxi;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(canEat(piles, mid, h, n)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};