class Solution {
public:
    vector<vector<int>> adjList;
    int dfs(vector<bool>& hasApple,int node,int d,int prev) {
        int result=0,temp;
        for(int &i:adjList[node])
        if(i!=prev) {
            temp=dfs(hasApple,i,d+1,node);
            if(temp)
            result+=temp-d;
        }
        return result||hasApple[node]?result+d:0;
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjList.resize(n);
        for(vector<int> &e:edges)
            adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
        return dfs(hasApple,0,0,-1)*2;
    }
};