class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            int minCost = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalin(s, i, j)) {
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }

    bool isPalin(string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
