class Solution {
    public:
    int nearestExit(vector<vector<char>>& m, vector<int>& e) {
        int r=size(m);
        int c=size(m[0]); 
        int i=e[0];
        int j=e[1];
        queue<pair<int,int>> q;
        int cnt=1;
        if(i+1<r and m[i+1][j]=='.') {
            q.push({i+1,j});
            m[i+1][j]='+';
        }
        if(i-1>=0 and m[i-1][j]=='.') {
            q.push({i-1,j});
            m[i-1][j]='+';
        }
        if(j+1<c and m[i][j+1]=='.') {
            q.push({i,j+1});
            m[i][j+1]='+';
        }
        if(j-1>=0 and m[i][j-1]=='.') {
            q.push({i,j-1});
            m[i][j-1]='+';
        }
        m[i][j]='+';
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();
                i = front.first;
                j = front.second;
                if(i==0 or j==0 or i==r-1 or j==c-1)
                return cnt;
                if(i+1<r and m[i+1][j]=='.') {
                    q.push({i+1,j});
                    m[i+1][j]='+';
                }
                if(i-1>=0 and m[i-1][j]=='.') {
                    q.push({i-1,j});
                    m[i-1][j]='+';
                }
                if(j+1<c and m[i][j+1]=='.') {
                    q.push({i,j+1});
                    m[i][j+1]='+';
                }
                if(j-1>=0 and m[i][j-1]=='.') {
                    q.push({i,j-1});
                    m[i][j-1]='+';
                }
            }
            cnt++;
        }
        return -1;
    }
};