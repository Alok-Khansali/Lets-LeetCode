// 1D dp,
/*
The idea here is to exploit the fact that from any index you can take at most 2 more steps
And that you have to take at least 1 more step
If there are same elements
  Choices are you can group in twos, or threes, or a mixture of 2s and 3s
If the numbers are consecutive, they have to be in groups of 3
If none of the above conditions are followed, answer is no
*/
// 100% faster, 80 ms
// Space 89.58 mb, 67.08% better
class Solution
{
public:
    int dp[100001];
    int res(int i, vector<int> &n)
    {
        if (i >= n.size())
            return 1;
        if (i == n.size() - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        if (n[i] == n[i + 1])
        {
            if (i + 1 == n.size() - 1)
                return dp[i] = 1;
            int x = res(i + 2, n);
            int y = (n[i] == n[i + 2]) ? res(i + 3, n) : 0;
            return dp[i] = (x | y);
        }
        else if (n[i] == n[i + 1] - 1)
        {
            if (i + 1 == n.size() - 1 || n[i + 1] != n[i + 2] - 1)
                return dp[i] = 0;
            int x = res(i + 3, n);
            return dp[i] = x;
        }
        return (dp[i] = 0);
    }
    bool validPartition(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return res(0, nums);
    }
};