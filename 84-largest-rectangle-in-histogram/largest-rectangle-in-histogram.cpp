class Solution {
private: 
    vector<int> getNextSmallerIndices(vector<int>& nums, int n) {
        vector<int> nse(n);
        stack<int> st;
    
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }
    vector<int> getPreviousSmallerIndices(vector<int>& nums, int n) {
        vector<int> pse(n);
        stack<int> st;
    
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = getNextSmallerIndices(heights, n);
        vector<int> pse = getPreviousSmallerIndices(heights, n);
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            int left = pse[i], right = nse[i];

            maxi = max(maxi, heights[i] * (right - left - 1));
        }

        return maxi;
    }
};