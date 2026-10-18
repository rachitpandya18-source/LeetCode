class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        int low = 1, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] > nums[mid - 1]) low = mid + 1;
            else if(nums[mid] > nums[mid + 1]) high = mid - 1;
            else low = mid + 1; // For Test Cases Like [1, 5, 1, 2, 1] when we are at 2nd index its reversal of peak so for finding answer we can go to either side
        }

        return -1;
    }
};