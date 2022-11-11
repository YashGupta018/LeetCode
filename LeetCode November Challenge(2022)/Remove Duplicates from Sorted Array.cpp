class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n<2)
            return n;
        int ans=1, j=0;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
                ans++;
            }
        }
        return ans;
    }
};