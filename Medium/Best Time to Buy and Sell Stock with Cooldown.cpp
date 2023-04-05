class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int j, c = prices.size(), have = prices[1] - prices[0], non = 0, nonn = 0, temp;
        for (int i = 2; i < c; i++)
            temp = have, have = max(have, nonn) + prices[i] - prices[i - 1], nonn = non, non = max(temp, non);
        return max(have, non);
    }
};