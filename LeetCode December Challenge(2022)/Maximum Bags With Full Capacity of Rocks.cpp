class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();	
        for(int i=0;i<n;i++) {
            capacity[i]-=rocks[i];
        }	
        sort(capacity.begin(),capacity.end());
        int ans=0;
        for(int i=0;i<n;i++) {
            ans+=capacity[i];
            if(ans>additionalRocks){
                return i;
            }
        }
        return n;
    }
};