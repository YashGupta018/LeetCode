class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total_cnt = 0;
        long long curr_cnt = 0;
        long long n = nums.size();
        for(long long i=0;i<n;i++) {
            if(nums[i]==0) {
                curr_cnt++;
                total_cnt += curr_cnt;
            }
            else {
                curr_cnt = 0;
            }
        }
        return total_cnt;
    }
};