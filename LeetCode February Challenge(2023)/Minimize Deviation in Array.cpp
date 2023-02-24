class Solution {
public:
    int minimumDeviation(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1) {
                arr[i] = 2 * arr[i];
            }
        }
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());        
        int ans = mx - mn;
        priority_queue<int> maxh;
        for(int i = 0; i < n; i++) {
            maxh.push(arr[i]);
        }
        while(maxh.top() % 2 == 0) {
            int top = maxh.top();
            maxh.pop();
            ans = min(ans, top - mn);
            top = top / 2;
            mn = min(mn, top);
            maxh.push(top);
        }
        ans = min(ans, maxh.top() - mn); 
        return ans;
    }
};