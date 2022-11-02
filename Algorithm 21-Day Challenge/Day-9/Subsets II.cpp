class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<string> seen;
        for (int mask = 0, size = 1 << n; mask < size; ++mask) {
            vector<int> subset;
            string hashcode = "";
            for (int i = 0; i < n; i++) {
                int bit = (mask >> i) & 1;
                if (bit == 1) {
                    subset.push_back(nums[i]);
                    hashcode += to_string(nums[i]) + ",";
                }
            }
            if (!seen.count(hashcode)) {
                ans.push_back(subset);
                seen.insert(hashcode);
            }
        }
        return ans;
    }
};