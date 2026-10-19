class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suffixMax(n, 0);
        suffixMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int leftMax = INT_MIN;
        int total = 0;
        for(int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            int rightMax = suffixMax[i];

            if(height[i] < leftMax && height[i] < rightMax) total += min(leftMax, rightMax) - height[i];
        }

        return total;
    }
};