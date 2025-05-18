// cause tle

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        string maxStr = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; i++) {
            string odd = expandFromCenter(s, i, i);      // Odd length center
            string even = expandFromCenter(s, i, i + 1); // Even length center

            if (odd.size() > maxStr.size())
                maxStr = odd;

            if (even.size() > maxStr.size())
                maxStr = even;
        }
        return maxStr;
    }

private:
    string expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // After expanding, left and right go one step too far
        return s.substr(left + 1, right - left - 1);
    }
};

//
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        string maxStr = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; i++) {
            string odd = expandFromCenter(s, i, i);      // Odd length center
            string even = expandFromCenter(s, i, i + 1); // Even length center

            if (odd.size() > maxStr.size())
                maxStr = odd;

            if (even.size() > maxStr.size())
                maxStr = even;
        }
        return maxStr;
    }

private:
    string expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // After expanding, left and right go one step too far
        return s.substr(left + 1, right - left - 1);
    }
};
