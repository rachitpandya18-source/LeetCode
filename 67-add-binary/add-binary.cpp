class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans;
        int n1 = a.length() - 1, n2 = b.length() - 1;

        int i = n1, j = n2;

        while(i >= 0 || j >= 0) {
            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            ans += to_string(sum % 2);
            carry = (sum > 1) ? 1 : 0;
        }

        if(carry) ans += to_string(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};