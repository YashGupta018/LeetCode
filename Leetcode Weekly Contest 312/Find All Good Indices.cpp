class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int a = nums.size();
        vector<int>left(a, 0), right(a, 0), result;
        for(int b = 1; b < a; b++){
            if(nums[b] <= nums[b - 1])
                left[b] = left[b - 1] + 1;
        }
        for(int b = a - 2; b >= 0; b--){
            if(nums[b] <= nums[b + 1])
                right[b] = right[b + 1] + 1;
        }
        for(int b = k; b <= a - k; b++){
            if(b - k >= 0 && b + k < a && left[b - 1] >= (k - 1) && right[b + 1] >= (k - 1))
                result.push_back(b);
        }
        return result;
    }
};