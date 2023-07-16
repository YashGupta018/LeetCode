class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = (int)req_skills.size();
        unordered_map<int, vector<int>> dp;
        unordered_map<string, int> skill_idx;
        dp.reserve(1 << n);
        dp[0] = {};
        for (int i = 0; i < n; i++) {
            skill_idx[req_skills[i]] = i;
        }
        for (int i = 0; i < (int)people.size(); i++) {
            int curr_skill = 0;
            for (auto s : people[i]) {
                curr_skill |= (1 << skill_idx[s]);
            }
            for (auto &[key, val] : dp) {
                int c = key | curr_skill;
                if (dp.find(c) == dp.end() or dp[c].size() > 1  + dp[key].size()) {
                    dp[c] = val;
                    dp[c].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};