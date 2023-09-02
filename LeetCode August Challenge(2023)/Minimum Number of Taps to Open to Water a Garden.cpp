class Solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        vector<vector<int>> intervals;
        for (int i = 0; i < ranges.size(); i++) {
            vector<int> inter{i - ranges[i], i + ranges[i]};
            intervals.push_back(inter);
        }
        sort(intervals.begin(), intervals.end(), [](auto &p, auto &q)
        { return (p[0] < q[0]); });
        int count = 0, start_time = 0, end_time = 0, i = 0;
        while (end_time < n) {
            for (; i < intervals.size() && intervals[i][0] <= start_time; i++) {
                end_time = max(end_time, intervals[i][1]);
            }
            if (start_time == end_time)
                return -1;
            start_time = end_time;
            count++;
        }
        return count;
    }
};