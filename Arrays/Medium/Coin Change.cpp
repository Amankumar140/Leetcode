class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);   
        int res = coin(coins, amount, dp);
        return (res == INT_MAX - 1) ? -1 : res;
    }

    int coin(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0; 
        if (amount < 0) return INT_MAX - 1;  

        if (dp[amount] != -2) return dp[amount];

        int ans = INT_MAX - 1;
        for (int c : coins) {
            int res = coin(coins, amount - c, dp);
            if (res != INT_MAX - 1)
                ans = min(ans, 1 + res);
        }

        return dp[amount] = ans;
    }
};
