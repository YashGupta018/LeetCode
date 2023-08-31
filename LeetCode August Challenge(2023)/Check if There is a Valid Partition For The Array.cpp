class Solution {
public:
    bool validPartition(std::vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return false;
        std::vector<bool> dp = {true, false, n > 1 && nums[0] == nums[1]};
        for (int i = 2; i < n; i++) {
            bool current_dp = false;
            if (nums[i] == nums[i - 1] && dp[1]) {
                current_dp = true;
            }
            else if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[0]) {
                current_dp = true;
            }
            else if (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1 && dp[0]) {
                current_dp = true;
            }
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current_dp;
        }
        return dp[2];
    }
};