class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minimum = nums[k];
        int max_score = nums[k];
        int i = k;
        int j = k;
        int n = nums.size();

        while (i > 0 || j < n - 1) {
            if (i > 0 && j < n - 1) {
                if (nums[i - 1] >= nums[j + 1]) {
                    i--;
                } else {
                    j++;
                }
            } else if (i == 0 && j < n - 1) {
                j++;
            } else if (j == n - 1 && i > 0) {
                i--;
            }
            minimum = min(minimum, min(nums[i], nums[j]));
            max_score = max(max_score, minimum * (j - i + 1));
        }
        return max_score;        
    }
};