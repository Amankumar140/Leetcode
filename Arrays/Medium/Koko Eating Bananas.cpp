class Solution {
public:
    long long possibleEat(int mid, const vector<int>& piles) {
        long long hr = 0;
        for (int i = 0; i < piles.size(); i++) {
            hr += (piles[i] + mid - 1LL) / mid;  // integer ceil without overflow
        }
        return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int end = *max_element(piles.begin(), piles.end());

        while (left <= end) {
            int mid = left + (end - left) / 2;
            long long x = possibleEat(mid, piles); // also change x to long long
            if (x <= h) {
                end = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
