class Solution {
public:
    typedef long long LONG;
    bool isValid(vector<int> &nums, int k) {
        if (nums[0] > k) return false;
        LONG prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            LONG d = k - prev;
            prev = nums[i] - d;
            if (prev > k) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int> &nums) {
        int res, left = 0, right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (isValid(nums, mid)) res = mid, right = mid - 1;
            else left = mid + 1;
        }
        return res;
    }
};