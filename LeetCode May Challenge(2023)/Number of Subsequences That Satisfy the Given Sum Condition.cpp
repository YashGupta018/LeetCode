class Solution {
public:
    int po(int x) {
        int y = 1, mod = 1e9+7,z = 2;
        while(x) {
            if(x&1) {
                y = (y*1LL*z)%mod;
            }
            x >>= 1;
            z = (z*1LL*z)%mod;
        }
        return y;
    }
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        sort(nums.begin(),nums.end());
        for(auto &i: nums)cout<<i<<" ";
        int ans = 0;
        int i,x,n=nums.size();
        for(i = 0; i < n; i++) {
            x = upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin();
            if(x-i-1<0)break;
            ans = (ans + po(x-i-1)%mod)%mod;
        }
        return ans;
    }
};