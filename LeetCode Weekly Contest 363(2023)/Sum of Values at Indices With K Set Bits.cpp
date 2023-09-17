class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            bitset<32> binary(i);
            if (binary.count() == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};