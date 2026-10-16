class Solution {
private:
    long long sumOfDivison(vector<int>& nums, int n, int divisor) {
        long long sum = 0;

        for(int i = 0; i < n; i++) sum += (long long)ceil((double)nums[i] / (double)divisor);

        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) maxi = max(nums[i], maxi);

        int low = 1, high = maxi;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(sumOfDivison(nums, n, mid) <= (long long)threshold) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};