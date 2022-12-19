class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++) {
            int v1 =edges[i][0];
            int v2 = edges[i][1];
            
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        vector<bool>visited(n,false);
        if(source==destination)
            return true;
        return path(source,destination,graph,visited);
    }
    bool path(int source,int destination,vector<vector<int>>&graph,vector<bool>&visited) {
        if(source==destination)
            return true;
        visited[source]=true;
        for(int i=0;i<graph[source].size();i++){
            if(visited[graph[source][i]]==false){
                if(path(graph[source][i],destination,graph,visited)==true)
                    return true;
            }
        }
        return false;
    }
};