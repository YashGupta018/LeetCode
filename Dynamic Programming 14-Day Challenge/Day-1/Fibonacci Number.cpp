class Solution {
    public:
    int t[31] = {0}; 
    int fib(int n) {
        if(n == 0 ||  n == 1)
            return n;
        t[0] = 0, t[1] = 1;
        for(int i = 2; i <= n; i++) {
            t[i] = t[i - 1] + t[i - 2];
        }
        return t[n];
    }
};