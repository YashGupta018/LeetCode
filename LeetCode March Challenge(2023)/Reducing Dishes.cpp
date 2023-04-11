class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
    sort(begin(sat), end(sat));
    int run_sum = accumulate(begin(sat), end(sat), 0), total_sum = 0;
    for (auto i = 0; i < sat.size(); ++i)
        total_sum += (i + 1) * sat[i];
    for (auto i = 0; run_sum < 0 && i < sat.size(); ++i) {
        total_sum -= run_sum;
        run_sum -= sat[i];
        }
    return total_sum;
    }
};