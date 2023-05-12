class Solution {
public:
    long long helper(int curr, vector<vector<int>>& questions, vector<long long> &dp) {
        if(curr >= questions.size()) {
            return 0;
        }
        if(dp[curr] != -1) {
            return dp[curr];
        }
        long long takeIt = questions[curr][0] + helper(curr + questions[curr][1]+1, questions, dp);
        long long skipIt = helper(curr+1, questions, dp);
        
        return dp[curr] = max(takeIt, skipIt);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return helper(0, questions, dp);
    }
};