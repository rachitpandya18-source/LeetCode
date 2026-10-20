class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int element = heights[st.top()];
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();

                maxi = max(maxi, element * (nse - pse - 1));
            }

            st.push(i);
        }

        while(!st.empty()) {
            int element = heights[st.top()];
            st.pop();
            int nse = n, pse = st.empty() ? -1 : st.top();

            maxi = max(maxi, element * (nse - pse - 1));
        }

        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += (matrix[i][j] - '0');

                if((matrix[i][j] - '0') == 0) sum = 0;

                prefixSum[i][j] = sum;
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, largestRectangleArea(prefixSum[i]));
        }

        return maxi;
    }
};