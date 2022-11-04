class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0) return 0;
        long long res = 1;
        for(int i = n; i < m+n-1 ; i++){
            res = res * i / (i- n + 1);
        }
        return (int)res;
    }
};