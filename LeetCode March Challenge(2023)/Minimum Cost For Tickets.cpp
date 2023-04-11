class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> tickets;
        tickets[1] = costs[0];
        tickets[7] = costs[1];
        tickets[30] = costs[2];
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<366; ++i) {
            if(find(days.begin(), days.end(), i) == days.end()) {
                dp[i] = dp[i-1];
                continue;
            }
            for(auto ticket : tickets) {
                dp[i] = min(dp[i], dp[max(0, i-ticket.first)] + ticket.second);
            }
        }
        return dp[365];
    }
};