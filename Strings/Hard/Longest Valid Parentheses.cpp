class Solution {
public:
    int longestValidParentheses(string str) {
        int maxlen = 0;

        stack<int> s;
        s.push(-1);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(')
                s.push(i);
            else {
                s.pop();
                if (s.empty()) {
                    s.push(i);
                } else {
                    maxlen = max(maxlen, i - s.top());
                }
            }
        }
        return maxlen;
    }
};
