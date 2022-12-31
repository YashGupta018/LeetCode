class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero = 0, x = 0, y = 0;   
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0) zero++;
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        return solve(grid, zero, x, y);
    }
    int solve(vector<vector<int>>& grid, int zero, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
            return 0;
        if(grid[x][y] == 2){
            if(zero == -1) return 1;
            else return 0;
        }
        grid[x][y] = -1;
        zero--;
        int ans = solve(grid, zero, x+1, y) + solve(grid, zero, x, y+1) + solve(grid, zero, x-1, y) + solve(grid, zero, x, y-1);
        grid[x][y] = 0;
        zero++;
        return ans;
    }
};