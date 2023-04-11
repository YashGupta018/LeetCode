class Solution {
public:
    void dfs(vector<int> adj[] , vector<int> &vis , int i) {
        vis[i]=1;
        for(auto a : adj[i]) {
            if(!vis[a]) {
                dfs(adj, vis, a);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(auto a : con) {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        int c = 0;
        int m = con.size();
        for(int i =0; i<n; i++) {
            if(!vis[i]){
                c++;
                dfs(adj,vis,i);
            }
        }
        if(m >= n-1) return c-1;
        return -1;
    }
};