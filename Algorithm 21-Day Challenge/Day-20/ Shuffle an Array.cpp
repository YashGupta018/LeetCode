class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    vector<int> reset() {
        return original;
    }
    vector<int> shuffle() {
        vector<int> shuffled = original;
        for (int i = original.size() - 1; i >= 0; i--) {
            int r = rand() % (i+1);
            swap(shuffled[i], shuffled[r]);
        }   
        return shuffled;
    }
private:
    vector<int> original;
};