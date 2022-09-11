class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> a;
        int sol = 0;
        for (int j = 0; j < intervals.size(); j++){
            int b = intervals[j][0], c = intervals[j][1];
            if(a.empty() || a.top() > intervals[j][0])
                sol += 1;
            else a.pop();
            a.push(intervals[j][1] + 1);
        }
        return sol;
    }
};