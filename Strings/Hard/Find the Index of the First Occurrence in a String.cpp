// using kmp and lps lc=easy
class Solution {
public:
    void lpsFind(vector<int>& lps, string s) {
        int pre = 0;
        int suf = 1;
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
         
    }
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        lpsFind(lps, needle);
        int second = 0;
        int first = 0;
        while (second < needle.size() && first < haystack.size()) {
            if (needle[second] == haystack[first]) {
                second++;
                first++;
            } else {
                if (second == 0)
                    first++;
                else {
                    second = lps[second - 1];
                }
            }
        }
        if (second == needle.size())
            return first - second;
        return -1;
    }
};
