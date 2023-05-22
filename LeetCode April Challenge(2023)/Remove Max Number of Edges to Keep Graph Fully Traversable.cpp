class Solution {
public:
    struct DisjointUnionSets {
    int *rank,*parent;
    int x;
    DisjointUnionSets(int n) {
        rank=new int[n];
        parent=new int[n];
        x=n;
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find(int x) {
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    bool Union(int x,int y) {
        int xRoot=find(x),yRoot=find(y);
        if(xRoot == yRoot)
            return false;
        if(rank[xRoot] < rank[yRoot])
            parent[xRoot]=yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot]=xRoot;
        else {
            parent[yRoot]=xRoot;
            rank[xRoot]++;
        }
        return true;
    }
};
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int size=edges.size();
        vector<pair<int,int>> alice;
        vector<pair<int,int>> bob;
        vector<pair<int,int>> both;
        for(int i=0;i<size;i++) {
            int temp=edges[i][0];
            if(temp==1)
                alice.push_back(make_pair(edges[i][1]-1,edges[i][2]-1));
            else if(temp==2)
                bob.push_back(make_pair(edges[i][1]-1,edges[i][2]-1));
            else
                both.push_back(make_pair(edges[i][1]-1,edges[i][2]-1));
        }
        DisjointUnionSets a(n),b(n);
        int res=0,componentA=n,componentB=n;
        for(auto x:both) {
            bool flag1=a.Union(x.first,x.second);
            bool flag2=b.Union(x.first,x.second);
            if(flag1)
                componentA--;
            if(flag2)
                componentB--;
            if(flag1 && flag2)
                res++;
        }
        for(auto x:alice) {
            bool flag=a.Union(x.first,x.second);
            if(flag) {
                componentA--;
                res++;
            }
        }
        for(auto x:bob) {
            bool flag=b.Union(x.first,x.second);
            if(flag) {
                componentB--;
                res++;
            }
        }
        if(componentA!=1 ||componentB!=1)
            return -1;
        return size-res;
    }
};