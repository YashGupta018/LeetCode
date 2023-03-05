class Solution {
    public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int> >m;
        for(int i=0;i<manager.size();i++) {
            m[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push(make_pair(headID,0));
        int maxi=0;
        while(!q.empty()) {
            int n=q.size();
            for(int i=0;i<n;i++) {
                int head=q.front().first;
                int timeTaken=q.front().second;
                q.pop();
                int dur=informTime[head]+timeTaken;
                maxi=max(maxi,dur);
                for(auto it:m[head]) {
                    q.push(make_pair(it,dur));
                }
            }
        }
        return maxi;
    }
};