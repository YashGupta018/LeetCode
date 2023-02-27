class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<pair<int, int>> s;
        int n = temperatures.size();
        s.push({temperatures[n - 1], n - 1});
        vector<int> gtr(n);
        gtr[n - 1] = 0;
        for (int i = n - 2; i > -1; i--) {
            while (!s.empty() && s.top().first <= temperatures[i]) {
                s.pop();
            }
            if (s.empty()) {
                s.push({temperatures[i], i});
                gtr[i] = 0;
            }
            else {
                gtr[i] = s.top().second - i;
                s.push({temperatures[i], i});
            }
        }
        return gtr;
    }
};