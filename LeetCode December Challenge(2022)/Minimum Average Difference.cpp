class Solution {
    public:
    int minimumAverageDifference(vector<int>& nums) {
        long i = 0, j = 0, m = LONG_MAX, k, d;
        long pfx = 0, sfx = accumulate(nums.begin(), nums.end(), 0L);
        for (int n : nums) {
            pfx += n, sfx -= n, j += 1;
            k = nums.size() - j;
            d = abs(pfx/j - sfx/(k?k:1));
            if (d < m) m = d, i = j - 1;
        }
        return i;
    }
};