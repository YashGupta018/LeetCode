class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {   
    }
    int next(int price) {
        int cnt = 1;
        while(!s.empty() && price >= s.top().first) {
            cnt += s.top().second;
            s.pop();
        }
        s.push({price,cnt});
        return s.top().second;
    }
};