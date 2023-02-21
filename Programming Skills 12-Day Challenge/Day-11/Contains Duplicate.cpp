class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int idx = 0; idx < nums.size() - 1; idx++) {
            if(nums[idx] == nums[idx + 1])
                return true;
        }
        return false;
    }
};