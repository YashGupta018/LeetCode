class Solution {
    public:
    int maximum69Number (int num) {
        int p = 1;
        int n = num;
        int maxp = 0;
        while(num>0) {
            int digit = (num % 10);
            if(digit==6) {
                maxp = p;
            }
            p*=10;
            num/=10;
        }
        n+=(maxp*3);
        return n;
    }
};