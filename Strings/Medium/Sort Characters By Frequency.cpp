class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        vector<pair<char, int>> f(m.begin(), m.end());
        sort(f.begin(), f.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
        string res;
        for (auto& [ch, freq] : f) {
            res.append(freq, ch); // append 'ch' 'freq' times
        }
        return res;
    }

};

// SC O(n) TCO(n)
class Solution {
public:
    string frequencySort(string s) {
        vector<int> a(62, 0);
        for (char c : s) {
            if (islower(c))
                a[c - 'a']++;
            else if (isupper(c))
                a[c - 'A'+26]++;
            if (isdigit(c))
                a[c - '0'+52]++;
        }
        string r;
        while (true) {
            int m = 0;
            int idx = -1;
            for (int i = 0; i < 62; i++) {
                if (a[i] > m) {
                    m = a[i];
                    idx = i;
                }
            }
            if (m == 0)
                break;
            char ch;
            if (idx < 26)
                ch = 'a' + idx;
            else if (idx < 52)
                ch = 'A' + (idx - 26);
            else
                ch = '0' + (idx - 52);
            while (m--)
                r += ch;
            a[idx] = 0;
        }
        return r;
    }
};
