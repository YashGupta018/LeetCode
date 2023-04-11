class Solution {
public:
    bool ok(vector<vector<int>>& grid , int i , int j , int n , int m) {
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 0);
    }
    void dfs(vector<vector<int>>& grid, int i , int j , int n , int m , int & cnt) {
        if(!ok(grid , i , j , n , m)) {
            return ;
        }
        if(grid[i][j] == 1) {
            cnt++;
        }
        grid[i][j] = 0;
        dfs(grid , i + 1 , j , n , m , cnt);
        dfs(grid , i - 1 , j , n , m , cnt);
        dfs(grid , i , j + 1 , n , m , cnt);
        dfs(grid , i , j - 1 , n , m , cnt);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int val = 0;
        for(int i = 0 ; i < m ; i++) {
            if(grid[0][i] == 1) {
                dfs(grid , 0 , i , n , m , val);
            }
            if(grid[n-1][i] == 1) {
                dfs(grid , n-1 , i , n , m , val);
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(grid[i][0] == 1) {
                dfs(grid , i , 0 , n , m , val);
            }
            if(grid[i][m-1] == 1) {
                dfs(grid , i , m-1 , n , m , val);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid , i , j , n , m , cnt);
                }
            }
        }
        return cnt;
    }
};