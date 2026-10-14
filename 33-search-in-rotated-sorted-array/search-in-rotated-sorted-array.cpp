class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]) { // Left Half of Array is Sorted
                if(nums[low] <= target && target < nums[mid]) // Target lies in the left half
                    high = mid - 1;
                else low = mid + 1;
            }
            else { // Right half of array is sorted
                if(nums[mid] < target && target <= nums[high]) // Target lies in the right half
                    low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};