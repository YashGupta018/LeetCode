class Solution {
public:
    int maxProfit(vector<int>& p) 
{
	if (p.size() < 2)
		return 0;
	int i, sz = p.size();
	int ret = 0;
	vector<int> buy(sz, 0);
	vector<int> sell(sz, 0);
	buy[0] = -p[0];
	for (i = 1; i < sz; ++i) {
		sell[i] = max(buy[i - 1] + p[i], sell[i - 1] - p[i - 1] + p[i]);
		if (ret < sell[i])
			ret = sell[i];
		if (1 == i)
			buy[i] = buy[0] + p[0] - p[1];
		else
			buy[i] = max(sell[i - 2] - p[i], buy[i - 1] + p[i - 1] - p[i]);
	}
	return ret;
    }
};