class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        vector<int> stops(n, INT_MAX);
        while(!pq.empty()) {
            auto temp=pq.top();
            int cdist=temp[0];
            int cnode=temp[1];
            int cstop=temp[2];
            pq.pop();
            if(cstop>stops[cnode] || cstop>k+1)
                continue;
            stops[cnode]=cstop;
            if(cnode==dst) {
                return cdist;
            }
            for(auto a : graph[cnode]) {
                pq.push({cdist+a.second, a.first, cstop+1});
            }
        }
        return -1;
    }
};