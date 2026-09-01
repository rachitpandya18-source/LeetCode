class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int maxi = -1;

        for(int i = n - 1; i >= 0; i--) {
            int original_val = arr[i];
            arr[i] = maxi;

            if(original_val > maxi) maxi = original_val;
        }

        return arr;
    }
};