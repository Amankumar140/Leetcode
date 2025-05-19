// normal approach..
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int c = 1;
        string repeat = a;
        while (repeat.size() < b.size()) {
            repeat += a;
            c++;
        }
        if (repeat.find(b) != string::npos) {
            return c;
        }
        repeat += a;
        if (repeat.find(b) != string::npos) {
            return c + 1;
        }

        return -1;
    }
};
// robin-karp method
