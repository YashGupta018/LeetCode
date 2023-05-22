class DisjointSet {
    public:
    vector<int>size;
    vector<int>parent;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findUpar(int node) {
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void UnionBySize(int u,int v) {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return ;
        if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b) {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i=0;i<queries.size();i++) {
            queries[i].push_back(i);
        }
        vector<bool>ans(queries.size(),false);
        sort(queries.begin(),queries.end(),cmp);
        sort(edgeList.begin(),edgeList.end(),cmp);
        int j=0;
        for(int i=0;i<queries.size();i++) {
            while(j<edgeList.size()&&edgeList[j][2]<queries[i][2]) {
                ds.UnionBySize(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            if(ds.findUpar(queries[i][0])==ds.findUpar(queries[i][1])) {
                ans[queries[i][3]]=true;
            }
        }
        return ans;
    }
};