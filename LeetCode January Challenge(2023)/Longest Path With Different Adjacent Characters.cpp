class Solution {
    pair<int , int> solve(vector<int> adj[] , string &s , int par , int &ans , vector<bool> &vis) {
        priority_queue<int> pq;
        vis[par] = 1;
        for(auto &x: adj[par]) {
            if(!vis[x]) {
                pair<int , int> p1 = solve(adj , s , x , ans , vis);
                if(p1.first != s[par]) {
                    pq.push(-p1.second);
                    if(pq.size() > 2)
                    pq.pop();
                }
            }
        }
        int mxnum = 0;
        int curmx = 0;
        if(pq.size() > 0) {
            int f = -pq.top();
            pq.pop();
            curmx+= f;
            mxnum = max(mxnum , f);
            }
        if(pq.size() > 0) {
            int f = -pq.top();
            pq.pop();
            curmx+= f;
            mxnum = max(mxnum , f);
            }
            curmx++;
            ans = max(ans,  curmx);
        return {s[par] , mxnum + 1 };
    }
    public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> adj[n];
        for(int i=1; i<n ; i++) {
            adj[i].push_back(parent[i]) ;
            adj[parent[i]].push_back(i) ;
            }
        vector<bool > vis(n , 0);
        int ans = 0;
        solve(adj , s , 0 , ans, vis) ;
    return ans ;
    }
};