class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
private:
    void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
        if (i == nums.size()) {
            perms.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++) {
                if (j == i || nums[j] != nums[i]) {
                    swap(nums[i], nums[j]);
                    permute(nums, i + 1, perms);
                }
            }
        }
    }
};