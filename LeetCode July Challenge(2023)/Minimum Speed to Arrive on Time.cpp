class Solution {
public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int m, ans = -1, n = dist.size();
        if (hour < n - 1)
            return -1;
        double dl = 0, dr = 0;
        for (auto d : dist) {
            double cur = d * 1.0;
            dl += (cur / hour);
            dr += (cur / (hour - n + 1));
        }
        int l = floor(min(dl, 10e7));
        int r = ceil(min(dr, 10e7));
        int mid;
        while (l <= r) {
            m = (l + r) / 2;
            if (check(dist, hour, m)) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
    bool check(vector<int> &dist, double hour, int speed) {
        double time = 0;
        int i = 0;
        while (time <= hour && i < dist.size() - 1) {
            time += ceil(static_cast<double>(dist[i]) / speed);
            i++;
        }
        time += static_cast<double>(dist[dist.size() - 1]) / speed;
        return (time <= hour);
    }
};