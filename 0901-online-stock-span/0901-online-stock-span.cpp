class StockSpanner {
private:
    stack<pair<int,int>> v;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int c = 1;
        while (!v.empty() && v.top().first <= price){
            c += v.top().second;
            v.pop();
        }
        v.push({price, c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */