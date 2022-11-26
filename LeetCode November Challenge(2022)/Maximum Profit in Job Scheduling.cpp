class Solution {
    public:    
    struct x {
        int start;  
        int end;    
        int profit;
    };
    static int sfn(x m, x n) {
        return m.end < n.end;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	    int sz = startTime.size(), dp[sz]; vector<x> y(sz);
        for(int i = 0; i < sz; i++) { y[i].start = startTime[i]; y[i].end = endTime[i]; y[i].profit = profit[i];
    }
    sort(y.begin(), y.end(), sfn);
    for (int i = 0; i < sz; i++) {
        if (!i) { 
            dp[i] = y[i].profit; continue;
        }
        int f = 0;
        for (int j = i - 1; j >= 0; j--) if (y[j].end <= y[i].start) {
            f = dp[j]; break;
        }    
        dp[i] = max(dp[i-1], f + y[i].profit );
        }    
    return dp[sz - 1];
    }
};