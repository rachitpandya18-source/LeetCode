class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> preSumMap;
        int prefixSum = 0;
        int count = 0;

        preSumMap[0] = 1;

        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int remain = prefixSum - k;

            count += preSumMap[remain];

            preSumMap[prefixSum]++;
        }

        return count;
    }
};