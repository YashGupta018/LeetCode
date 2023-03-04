class Solution {
    public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        std::vector<bool> res;
        for (int i = 0; i < r.size(); i++) {
            std::vector<int> arr(nums.begin() + l[i], nums.begin() + 1 + r[i]);
            sort(arr.begin(), arr.end());
            if(arr.size() == 1) {
                res.push_back(false);
                continue;
                }
            int diff = arr[1] - arr[0];
            bool valid =  true;
            for (int j = 2; j < arr.size(); j++)
            if (arr[j] - arr[j - 1] != diff) {
                valid = false;
                break;
                }
            res.push_back(valid);
            }
        return res;
    }
};