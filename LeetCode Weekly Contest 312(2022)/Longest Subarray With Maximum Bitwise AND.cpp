class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a = nums.size();
        int b = INT_MIN;
        for(auto it : nums){
            b = max(b, it);
        }
        int result = 0;
        for(int c = 0; c < a; c++){
            if(nums[c] == b){
                int d = 0;
                int e = c;
                while(e < a && nums[e] == nums[c]){
                    d++;
                    e++;
                }
                c = e - 1;
                result = max(result, d);
            }
        }
        return result;
    }
};