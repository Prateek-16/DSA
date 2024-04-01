//https://leetcode.com/problems/online-stock-span/description/

//Online Stock Span

class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        pair<int,int>p;
        while( !st.empty() && (st.top().first)<=price){
            span+=st.top().second;
            st.pop();
        }
        p.first=price;
        p.second=span;
        st.push(p);
        return p.second;
        
    }
};
