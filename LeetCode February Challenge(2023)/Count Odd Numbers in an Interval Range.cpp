class Solution {
public:
    int countOdds(int low, int high) {
        int odd_lowerbound=-1, odd_upperbound=-1;
        if( low % 2 == 1) {
            odd_lowerbound = low;
        }
        else {
            odd_lowerbound = low+1;
        }
        if( high % 2 == 1) {
            odd_upperbound = high;

        }
        else {
            odd_upperbound = high-1;
        }
        return 1 + ((odd_upperbound - odd_lowerbound) / 2);
    }
};