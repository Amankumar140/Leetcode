class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool isdot = false, num = false, ise = false;

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = true;
            } else if (s[i] == '+' || s[i] == '-') {

                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (ise || !num)
                    return false;
                ise = true;
                num = false;
            } else if (s[i] == '.') {
                if (isdot || ise)
                    return false;
                isdot = true;
            } else {
                return false;
            }
        }

        return num;
    }
};
