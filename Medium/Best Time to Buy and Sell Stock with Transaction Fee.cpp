// Dynamic Programming with O(N^2) Space
// Solution holds but exceeds the memory limits
class Solution
{
public:
    vector<vector<int>> dp;
    int do_it(int i, int j, vector<int> &v, int l, int fee)
    {
        if (i >= l - 1 || j >= l)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            j++;
        if (v[j] - v[i] - fee >= 0)
            dp[i][j] = max(v[j] - v[i] - fee + do_it(j + 1, j + 2, v, l, fee), do_it(i, j + 1, v, l, fee));
        else
            dp[i][j] = max(do_it(i + 1, j, v, l, fee), do_it(i, j + 1, v, l, fee));
        return dp[i][j];
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        int len = prices.size();
        dp.resize(len, vector<int>(len, -1));
        return do_it(0, 0, prices, len, fee);
    }
};
// Efficient Solution 
/*
Understand that the maximum profit is the sum of all increasing gradients,
but the use of fee, prevents the usage of every increasing slope
*/