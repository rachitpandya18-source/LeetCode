class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long temp = 1;
        ans.push_back(temp);

        for(int i = 1; i <= rowIndex; i++) {
            temp = temp * (rowIndex - i + 1);
            temp = temp / i;

            ans.push_back(temp);
        }
        return ans;
    }
};