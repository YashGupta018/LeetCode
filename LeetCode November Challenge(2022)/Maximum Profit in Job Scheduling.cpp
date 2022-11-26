class Solution {
    public:
    int maxProfit(vector<vector<int>>& jobs, int idx, const int& n) {
        if(idx == n) return 0;
        int next = getNextJob(jobs, idx, n);
        int incl = jobs[idx][2] + maxProfit(jobs, next, n);
        int excl = maxProfit(jobs, idx+1, n);
        return max(incl, excl);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        
        for(int i=0; i<n; i++) {
            jobs[i][0] = startTime[xi];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), compare);
    return maxProfit(jobs, 0, n);
    }
};