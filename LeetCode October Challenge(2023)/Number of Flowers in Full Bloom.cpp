class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& nums, vector<int>&p) {
        vector<int>ans(p.size());
        multiset<long long>mp;
        sort(nums.begin(),nums.end());
        vector<vector<long long>>v;
        for(int i=0;i<p.size();i++) {
            v.push_back({p[i],i});
        }
        sort(v.begin(),v.end());
        int j=0;
        for(int i=0;i<v.size();i++) {
            while(j<nums.size()&&v[i][0]>=nums[j][0]) {
                mp.insert(nums[j][1]);
                j++;
            }
            while(mp.size()&&v[i][0]>(*mp.begin())) {
                mp.erase(mp.begin());
            }
            ans[v[i][1]]=mp.size();
        }
        return ans;
    }
};