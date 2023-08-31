class Solution {
public:
    int bestClosingTime(string custom) {
        int y=0,n=0;
        for(auto i:custom) {
            if(i=='Y')y++;
        }
        int mn = INT_MAX,index,penalty;
        for(int i=0;i<custom.size();i++) {
            penalty = y + n;
            if(penalty<mn) {
                mn = penalty;
                index = i;
            }
            if(custom[i]=='Y')y--;
            else n++;
        }
        penalty = y + n;
        if(penalty<mn) {
                mn = penalty;
                index = custom.size();
        }
        return index;
    }
};