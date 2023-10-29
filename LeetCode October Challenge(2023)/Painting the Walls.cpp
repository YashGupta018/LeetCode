class Solution {
public:
    vector<vector<int>> memo;
    int n;
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memo = vector(n, vector(n + 1, -1));
        return dp(0, n, cost, time);
    }
    
    int dp(int i, int remain, vector<int>& cost, vector<int>& time) { 
        if (remain <= 0) {
            return 0;
        }
        
        if (i == n) {
            return 1e9;
        }
        
        if (memo[i][remain] != -1) {
            return memo[i][remain];
        }
        
        int paint = cost[i] + dp(i + 1, remain - 1 - time[i], cost, time);
        
        int dontPaint = dp(i + 1, remain, cost, time);
        
        memo[i][remain] = min(paint, dontPaint);
        
        return memo[i][remain];
    }
};