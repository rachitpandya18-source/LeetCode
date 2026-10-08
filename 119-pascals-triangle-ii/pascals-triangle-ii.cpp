class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long currentVal = 1;

        for(int col = 0; col < rowIndex; col++) {
            currentVal *= (rowIndex - col);
            currentVal /= (col + 1);
            ans.push_back(currentVal);
        }
        return ans;
    }
};