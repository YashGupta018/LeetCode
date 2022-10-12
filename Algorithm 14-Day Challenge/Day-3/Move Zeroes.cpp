class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::stable_partition(nums.begin(), nums.end(), [](int n){return n!=0;});
    }
};