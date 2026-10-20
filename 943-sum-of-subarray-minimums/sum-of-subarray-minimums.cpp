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
    vector<int> getPreviousSmallerEqualIndices(vector<int>& nums, int n) {
        vector<int> psee(n);
        stack<int> st;
    
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = getNextSmallerIndices(arr, n);
        vector<int> psee = getPreviousSmallerEqualIndices(arr, n);
        int total = 0, mod = (int)1e9 + 7;
        for(int i = 0; i < n; i++) {
            long long left = i - nse[i], right = psee[i] - i;

            total = (total + ((left * right * 1LL * arr[i]) % mod)) % mod;
        }

        return total;
    }
};