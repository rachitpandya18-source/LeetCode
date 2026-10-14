class Solution {
public:
// In here only one edge is limiting us from using the approach used in Part I which is
// [3, 3, 1, 3, 3, 3] -> So you can see that by checking boundries and mid you cannot identify which half is sorted correctly 
// So to solve this edge case just trim down the search space low++ and high-- and after that skip that particular iteration
// And for T.C. in the worst case it will be O[n / 2] when in test case all elements are same but the target
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++, high--;
                continue;
            }
            
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

        return false;
    }
};