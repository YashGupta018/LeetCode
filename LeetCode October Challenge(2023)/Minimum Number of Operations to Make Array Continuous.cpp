class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int newLen = unique(nums.begin(), nums.end()) - nums.begin();
        int l = 0, r = 0, fin = 1;
        while (r < newLen) {
            if (l == r)
                r++;
            else if (nums[r] - nums[l] > k)
                l++;
            else {
                fin = max(fin, r - l + 1);
                r++;
            }
        }
        return k - fin + 1;
    }
};