class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        vector<int> res(num + 1, 0);
        res[0] = 0;
        res[1] = 1;
        for (int i = 2; i <= num; i++)
            res[i] = res[i / 2] + i % 2;
        return res;
    }
};