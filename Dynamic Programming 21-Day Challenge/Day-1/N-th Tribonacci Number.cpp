class Solution {
    public:
    int t0=0, t1=1, t2=1;
    long long int arr[38]={0};
    int tribonacci(int n) {
        
        if(n==0)
            return t0;
        if(n==1)
            return t1;
        if(n==2)
            return t2;
        if(arr[n]!=0)
            return arr[n];
        return arr[n]=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        
    }
};