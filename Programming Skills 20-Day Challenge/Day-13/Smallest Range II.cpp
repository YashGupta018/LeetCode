class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int N  = nums.size();
        sort(nums.begin(), nums.end());
        int score = nums[N-1] - nums[0];
        int ans   = score;
        for (int divider = 0; divider < N-1; divider++) {
            int maximumAfterDivision = max(nums[divider]    + k , nums[N-1] - k);
            int minimumAfterDivision = min(nums[divider+1]  - k , nums[0]  + k);
            score = maximumAfterDivision - minimumAfterDivision;
            ans = min(ans, score);
        }
        return ans;
    }
};