// TC O(n*log(m))
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            gcd = gcdfun(gcd, nums[i]);
        }
        return gcd == 1;
    }
    int gcdfun(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
