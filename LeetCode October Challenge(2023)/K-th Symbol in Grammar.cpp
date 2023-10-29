class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int parent = kthGrammar(n - 1, ceil(k / 2.0));
        bool isOdd = k % 2 == 1;
        if (parent == 1) {
            return isOdd ? 1 : 0;
        }
        else {
            return isOdd ? 0 : 1;
        }        
    }
};