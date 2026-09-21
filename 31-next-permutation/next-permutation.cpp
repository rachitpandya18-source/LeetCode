class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int brePoint = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                brePoint = i;
                break;
            }
        }

        if(brePoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i >= brePoint; i--) {
            if(nums[i] > nums[brePoint]) {
                swap(nums[i], nums[brePoint]);
                break;
            }
        }

        reverse(nums.begin() + brePoint + 1, nums.end());
    }
};