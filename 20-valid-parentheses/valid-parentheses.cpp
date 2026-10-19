class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {
            if(ch == '[' || ch == '{' || ch == '(') st.push(ch);
            else {
                if(st.empty()) return false;

                char temp = st.top();
                if(ch == ']' && temp == '[' || ch == '}' && temp == '{' || ch == ')' && temp == '(') st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};