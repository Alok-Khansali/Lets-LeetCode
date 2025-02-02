class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int len = prices.size();
        stack<int> st;
        st.push(prices[len - 1]);
        vector<int> ans(len);
        ans[len - 1] = prices[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            ans[i] = prices[i];
            while (!st.empty() && st.top() > prices[i])
                st.pop();
            if (!st.empty())
                ans[i] -= st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};