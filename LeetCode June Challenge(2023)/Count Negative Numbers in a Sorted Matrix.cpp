class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n,m;
        n=grid.size();m=grid[0].size();
        int total=0;
        for(int i=0;i<n;i++) {
            int l=0,r=m-1,ans=m;
            while(l<=r) {
                int mid=(l+r)/2;
                if(grid[i][mid]<0) {
                    r=mid-1;
                    ans=mid;
                }
                else l=mid+1;
            }
            total += m-ans;
        }
        return total;
    }
};