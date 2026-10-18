class Solution {
private:
    bool canMake(vector<int>& bloomDay, int m, int k, long days) {
        int counter = 0, totalBouquets = 0;
        int n = bloomDay.size();
        for(int i = 0; i < n; i++) {
            if((long)bloomDay[i] <= days) counter++;
            else counter = 0;

            if(counter == k) {
                totalBouquets++;
                counter = 0;
            }
            if(totalBouquets == m) return true;
        } 

        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long mini = INT_MAX, maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            mini = min(mini, (long)bloomDay[i]);
            maxi = max(maxi, (long)bloomDay[i]);
        }

        long low = mini, high = maxi;
        long ans = -1;
        while(low <= high) {
            long days = low + (high - low) / 2;

            if(canMake(bloomDay, m, k, days)) {
                ans = days;
                high = days - 1;
            }
            else low = days + 1;
        }

        return ans;
    }
};