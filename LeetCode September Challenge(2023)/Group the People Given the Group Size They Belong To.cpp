class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        int n=groupSizes.size();
        for(int i=0; i<n; i++) {
            int x=groupSizes[i];
            mp[x].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto& [x, v]: mp) {
            int sz=v.size();
            auto [q, r]=div(sz, x);
            if (r!=0) 
                return vector<vector<int>>();
            for(int i=0; i<q; i++) {
                vector<int> v_sz(x);
                copy(v.begin()+(i*x), v.begin()+((i+1)*x), v_sz.begin());
                ans.push_back(v_sz);
            }
        }
        return ans;
    }
};