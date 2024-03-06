class StockSpanner {
public:
    
    stack <pair <int, int>> prices;
    
    StockSpanner() {
 
    }
    int next(int price) {
        int ans = 1;
                
        while (!prices.empty() && (prices.top().first <= price)) {
            ans += prices.top().second;
            prices.pop();
        }
        prices.push({price, ans});
        
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */