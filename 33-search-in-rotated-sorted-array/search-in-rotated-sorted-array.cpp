class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]) { // left half is sorted
                if(target >= nums[low] && target <= nums[mid]) high = mid - 1; // it lies in the left half
                else low = mid + 1; // otherwise it lies in the right half
            }
            else { // right half is sorted
                if(target >= nums[mid] && target <= nums[high]) low = mid + 1; // it lies in the right half
                else high = mid - 1; // otherwise it lies in the left half
            }
        }

        return -1;
    }
};