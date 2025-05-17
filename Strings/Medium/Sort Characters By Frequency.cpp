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
