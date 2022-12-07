class Solution {
public:
    int jump(vector<int>& nums) {    
        int numOfJumps = 0, currentIntervalEnd = 0, farthestReachFoundSoFar = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            farthestReachFoundSoFar = max(farthestReachFoundSoFar, i + nums[i]);
            if(i == currentIntervalEnd) {
                numOfJumps++;
                currentIntervalEnd = farthestReachFoundSoFar;
            }
        }
        return numOfJumps;
    }
};