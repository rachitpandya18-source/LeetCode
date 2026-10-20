class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> nge;

        for(int i = n2 - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();

            if(st.empty()) nge[nums2[i]] = -1;
            else nge[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> res;
        for(int i = 0; i < n1; i++) {
            res.push_back(nge[nums1[i]]);
        }

        return res;
    }
};