class Solution {
    bool check(vector<int>& weights, int days, int mid) {
        int sum = 0;
        for(int w: weights) {
            if(w > mid) return false;
            sum += w;
            if(sum > mid) {
                days--;
                sum = w;
            }
        }
        return days > 0;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 1e8;
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(weights, days, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};