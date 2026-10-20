class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= i + n - 1; j++) {
                int idx = j % n;
                if(nums[i] < nums[idx]) {
                    res[i] = nums[idx];
                    break;
                }
            }
        }

        return res;
    }
};