// brute O(n^3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
         vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// better TC O(n^2) SC O(unique triplets+n)
// using two sum approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            int tar=-nums[i];
            set<int> s;
            for (int j = i + 1; j < nums.size(); j++) {
                 int third=tar-nums[j];
                 if(s.find(third)!=s.end()){
                    vector<int> triplets={nums[i], nums[j], third};
                    sort(triplets.begin(), triplets.end());
                    st.insert(triplets);
                 }
                 s.insert(nums[j]);
            }
        }
         vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


// best optimal two pointer approach 
// O(n^2) in worst case SC O(k)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    j++;
                    k--;
                    res.push_back(trip);
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }
        return res;
    }
};
