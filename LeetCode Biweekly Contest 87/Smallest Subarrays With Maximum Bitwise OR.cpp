class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> result;
        int a = nums.size();
        vector<int> nearest(32, -1);
        for (int b = a -1; b >= 0; b--){
            for (int c = 0; c < 32; c++){
                if (nums[b] & (1 << c))
                    nearest[c] = b;
            }
            int last_set = b;
            for (int c = 0; c < 32; c++)
                last_set = max(last_set, nearest[c]);
                result.push_back(last_set - b + 1);
        }
            reverse(result.begin(), result.end());
            return result;
    }
};