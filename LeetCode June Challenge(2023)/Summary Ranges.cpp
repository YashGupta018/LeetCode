class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size(); 
        int prevIndex = 0; 
        for(int i = 1; i <= n; i++) {
            if(i < n and nums[i] == nums[i-1]+1) {
                continue;
            }
            else {
                int currIndex = i-1;
                if(currIndex == prevIndex) {
                    ans.push_back(to_string(nums[prevIndex]));
                }
                else {
                    ans.push_back(to_string(nums[prevIndex]) + "->" + to_string(nums[currIndex]));
                }
                prevIndex = i;
            }
        }
        return ans; 
    }
};