class Solution {
private:
    int findFirstOccur(vector<int>& nums, int n, int target) {
        int first = -1, low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return first;
    }
    int findLastOccur(vector<int>& nums, int n, int target) {
        int last = -1;
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = findFirstOccur(nums, n, target);
        if(first == -1) return {-1, -1};

        return {first, findLastOccur(nums, n, target)};
    }
};