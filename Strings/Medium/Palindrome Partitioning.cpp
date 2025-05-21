class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
         helper(s, res, sub, 0);
         return res;
    }
    void helper(const string& s, vector<vector<string>>& res,
                vector<string>& sub, int i) {
        if (i >= s.length()) {
            res.push_back(sub);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (isPal(s, i, j)) {
                sub.push_back(s.substr(i, j - i + 1));
                helper(s, res, sub, j + 1);
                sub.pop_back();
            }
        }
    }
    bool isPal(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
