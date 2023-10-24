class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            ++umap[nums[i]];
        }
        int good_pairs = 0;
        for(auto i:umap) {
            int n = i.second;
            good_pairs += ((n)*(n-1))/2;
        }
        return good_pairs;
    }
};
    