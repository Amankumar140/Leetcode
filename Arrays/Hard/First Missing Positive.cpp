class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size()) {
                int correct = nums[i] - 1;
                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                    continue;
                }
            }
            i++;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return nums.size() + 1;
    }
};
