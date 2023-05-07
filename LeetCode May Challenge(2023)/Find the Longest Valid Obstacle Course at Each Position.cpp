class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> res(n,1);
        vector<int> lis;
        lis.push_back(obstacles[0]);
        for(int i=1;i<n;i++) {
            if(lis.back()<=obstacles[i]) {
                lis.push_back(obstacles[i]);
                res[i]=lis.size();
            }
            else {
                int idx=(upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin());
                lis[idx]=obstacles[i];
                res[i]=idx+1;
            }
        }
        return res;
    }
};