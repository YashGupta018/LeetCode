class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minelem=prices[0];
        for(int i=1;i<prices.size();i++) {
            minelem=min(prices[i],minelem);
            profit=max(profit,(prices[i]-minelem));
        }
        return profit;
    }
};