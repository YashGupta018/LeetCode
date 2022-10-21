class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hset;
        for(int idx = 0; idx < nums.size(); idx++) {
            if(hset.count(nums[idx]))
                return true;
            hset.insert(nums[idx]);
            if(hset.size() > k)
                hset.erase(nums[idx - k]);
        }
        return false;
    }
};