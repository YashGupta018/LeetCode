class Solution {
public:
    int next(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }   
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1 ;
    }
};