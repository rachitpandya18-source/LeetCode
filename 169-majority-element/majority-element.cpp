class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        long long el;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(count == 0) {
                el = nums[i];
                count = 1;
            }
            else if(nums[i] == el) count++;
            else count--;
        }
        return el;
    }
};