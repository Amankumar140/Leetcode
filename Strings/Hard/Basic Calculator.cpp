
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0;
        int num = 0;
        int sign = 1;

        st.push(sign);
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+' || ch == '-') {
                ans += sign * num;
                sign = st.top() * (ch == '+' ? 1 : -1);
                num = 0;
            } else if (ch == '(') {
                st.push(sign);
            } else if (ch == ')') {
                st.pop();
            }
        }
        ans += sign * num;
        return ans;
    }
};
