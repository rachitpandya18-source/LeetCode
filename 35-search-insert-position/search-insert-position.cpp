class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // By checking its test cases this problem is straight up telling us to give lower bound of the target
        int n = nums.size();
        int low = 0, high = n - 1;

        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) { // Maybe an answer
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1; // Can not be an answer
        }

        return ans;
    }
};