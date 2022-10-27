class Solution 
{
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        size_t n = img1.size();
        vector<pair<int32_t,int32_t>> idx1, idx2;
        for (int i = 0; i < n*n; i++)
            if (img1[i/n][i%n]) idx1.emplace_back(i/n, i%n);
        for (int j = 0; j < n*n; j++)
            if (img2[j/n][j%n]) idx2.emplace_back(j/n, j%n);
        vector<int> tr_vecs(2*n * 2*n, 0);
        size_t vx, vy;
        for (auto [i1,i2] : idx1)
            for (auto [j1,j2] : idx2)
            {
                vx = (2*n+i1-j1) % (2*n);
                vy = (2*n+i2-j2) % (2*n);
                tr_vecs[vx*(2*n) + vy] += 1;
            }
        return *max_element(tr_vecs.begin(), tr_vecs.end());
    }
};