class Solution {
    public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        for (auto i : queries) {
            int count = 0;
            int k;
            for (k = 0; k < nums.size(); k++) {
                if (count + nums[k] > i)
                    break;
            }
            ans.push_back(k);
        }
        return ans;
    }
};