class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for (int i : nums) {
            target += i;
        }
        target -= x;
        if (target < 0) {
            return -1;
        }
        int left = 0;
        int curSum = 0;
        int maxSubLength = INT_MIN;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            curSum += nums[right];
            while (curSum > target) {
                curSum -= nums[left];
                left++;
            }
            if (curSum == target) {
                maxSubLength = std::max(maxSubLength, right - left + 1);
            }
        }
        return maxSubLength == INT_MIN ? -1 : n - maxSubLength;        
    }
};