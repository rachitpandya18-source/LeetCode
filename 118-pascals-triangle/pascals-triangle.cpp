class Solution {
private:
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
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pTriangle;
        for(int i = 0; i < numRows; i++) {
            pTriangle.push_back(getRow(i));
        }

        return pTriangle;
    }
};