class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum_of_digits = 0, product_of_digits = 1;
        string num = to_string(n);
        for(char ch : num) {
            int digit = ch-'0';
            sum_of_digits += digit;
            product_of_digits *= digit;
        }
        return product_of_digits-sum_of_digits;
    }
};