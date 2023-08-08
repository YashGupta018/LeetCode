class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto skip_left = [&](int x) { return x >= nums[0] ? numeric_limits<int>::min() : x; };
        auto skip_right = [&] (int x) { return x < nums[0] ? numeric_limits<int>::max() : x; };
        auto adjust = [&] (int x) { return target < nums[0] ? skip_left(x) : skip_right(x); };
        auto it = lower_bound( nums.begin(), nums.end(), target, [&] (int x, int y) { return adjust(x) < adjust(y); } );
        return it != nums.end() && *it == target ? it-nums.begin() : -1;
    }
};