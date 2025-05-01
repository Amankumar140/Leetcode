// Prob:- 2149. Rearrange Array Elements by Sign
// brute force/ naive sol 
// TC = O(n) SC=O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int>neg;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            } else{
                pos.push_back(nums[i]);
            }
        }
        int j=0,k=0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                nums[i]=pos[j++];
            } else{
                nums[i]=neg[k++];
            }
        }
        return nums;
    }
};


// optimise 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx=0;
        int negIdx=1;
        vector<int> res(nums.size());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                res[posIdx]=nums[i];
                posIdx+=2;
            } else{
                res[negIdx]=nums[i];
                negIdx+=2;
            }
        }
        return res;
    }
};
