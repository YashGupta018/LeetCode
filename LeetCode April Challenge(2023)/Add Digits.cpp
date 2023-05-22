class Solution {
public:
    int addDigits(int n) {
        long long num = n;
        while(num>9){
            long long tp=0;
            while(num >0) {
                tp+= num%10;
                num/=10;
            }
            num = tp;
        }
        return num;
    }
};