// First Draft, Using the monotonic Stack, Simply checking
// For the first value greater than the Given one
class StockSpanner
{
    // Runtime: 212 ms, faster than 98.61% of C++ online submissions for Online Stock Span.
    // Memory Usage: 84 MB, less than 99.96% of C++ online submissions for Online Stock Span.
public:
    stack<pair<int, int>> st;
    int x = 1;
    StockSpanner() {}
    int next(int price)
    {
        ios_base::sync_with_stdio(0);
        int y = 0;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        y = x - (st.empty() ? 0 : st.top().second);
        st.push({price, x++});
        return y;
    }
};