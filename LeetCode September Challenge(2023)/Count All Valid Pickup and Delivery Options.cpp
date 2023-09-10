class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        long long answer = 1;
        for(int i = 2; i <= n; i++) {
            answer = (answer * i * (2 * i - 1))%mod;
        }
        return (int) answer;
    }
};