//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought1 = INT_MAX, bought2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for (int price : prices) {
            bought1 = min(bought1, price);
            profit1 = max(profit1, price - bought1);
            bought2 = min(bought2, price - profit1);
            profit2 = max(profit2, price - bought2);
        }
        return profit2;
    }
};
