class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int c=1;
        vector<int>tem;
        while(!st.empty() && st.top().first<=price){
            c=c+st.top().second;
            // tem.push_back(st.top());
            st.pop();
        }
        /*
        reverse(tem.begin(),tem.end());
        int i=0;
        while(i<tem.size()){
            st.push(tem[i++]);
        }
        */
        st.push({price,c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */