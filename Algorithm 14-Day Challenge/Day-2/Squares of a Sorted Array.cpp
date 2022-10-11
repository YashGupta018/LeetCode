class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        vector<int>v(n);
        int k=n-1;
        while(low<=high){
            if(abs(nums[low]) > abs(nums[high])){
                v[k--]=nums[low] * nums[low];
                low++;
            }
            else{
                v[k--]=nums[high] * nums[high];
                high--;
            }
        }
        return v; 
    }
};