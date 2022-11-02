class Solution {
public:
    void helper(int index, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds) {
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i< candidates.size(); i++) {
            if(candidates[i] > target) break;
            if(i  > index && candidates[i] == candidates[i-1])
                continue;
            ds.push_back(candidates[i]);
            helper(i+1, target- candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};