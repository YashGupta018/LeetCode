class Solution {
public:
    long long minimumReplacement(vector<int> &nums) {
        int currentLargest = nums[nums.size() - 1];
        long totalReplacements = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= currentLargest) {
                currentLargest = nums[i];
                continue;
            }
            int numElements;
            if (nums[i] % currentLargest != 0) {
                numElements = nums[i] / currentLargest + 1;
                currentLargest = nums[i] / numElements;
            }
            else {
                numElements = nums[i] / currentLargest;
            }
            totalReplacements += numElements - 1;
        }
        return totalReplacements;
    }
};