class Solution {
    public:
    int findMaximizedCapital(int k, int W, vector<int>& P, vector<int>& C) {
        priority_queue<int> low;
        multiset<pair<int,int>> high;
        for (int i = 0; i < P.size(); ++i)
        if(P[i] > 0) if (C[i] <= W) low.push(P[i]); else high.emplace(C[i], P[i]);
        while (k-- && low.size()) { 
            W += low.top(), low.pop();
            for (auto i = high.begin(); high.size() && i->first <= W; i = high.erase(i)) low.push(i->second);
            }
        return W;
    }
};