class Solution {
public:
    int DP(vector<int>& nums,int index,vector<int>&dp){
        if(index>=nums.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        return dp[index] = max(nums[index]+DP(nums,index+2,dp),DP(nums,index+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return DP(nums,0,dp);
    }
};