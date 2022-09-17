class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int c = 0, d = 0, e = 0;
        while(c < players.size() and d < trainers.size()){
            if(players[c] <= trainers[d]){
                e++;
                c++;
                d++;
            }
            else{
                d++;
            }
        }
        return e;
    }
};