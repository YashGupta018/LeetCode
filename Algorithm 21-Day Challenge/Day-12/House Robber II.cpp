class Solution {
public:
    int solve(int &s,int &e,vector<int> &nums){
        int in = 0, ex = 0,z;
        for(int i = s; i <= e; i++){
            z = max(in,ex+nums[i]);
            ex = in;
            in = z;
        }
        return in;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        else if(n==2)return max(nums[0],nums[1]);
        int s = 0, e = n-2;
        int ans1 = solve(s,e,nums);
        s = 1, e = n-1;
        int ans2 = solve(s,e,nums);
        return max(ans1,ans2);
    }
};