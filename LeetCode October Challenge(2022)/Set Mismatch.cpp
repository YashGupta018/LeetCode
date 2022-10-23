class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size(), tot = 0;
        vector<int> res(2);
        for (int n: nums) {
            n = abs(n);
            tot += n;
            if (n == len) n = 0;
            if (nums[n] < 0) res[0] = n ? n : len;
            else nums[n] *= -1;
        }
        res[1] = (len + 1) * len / 2 - tot + res[0];
        return res;
    }
};