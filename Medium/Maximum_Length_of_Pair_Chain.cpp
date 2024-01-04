// Dynamic Programming Approach
class Solution
{
public:
    vector<vector<int>> dp;
    int mx = 1;
    int doit(int i, int prev, int n, vector<vector<int>> &p)
    {
        if (i >= n)
            return 0;
        if (dp[i][prev] != -1)
            return dp[i];
        if (p[i][0] <= p[prev][1])
            return dp[i][prev] = doit(i + 1, prev, n, p);
        dp[i][prev] = max(1 + doit(i + 1, i, n, p), doit(i + 1, prev, n, p));
        mx = max(dp[i][prev], mx);
        return dp[i][prev];
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());
        dp.assign(pairs.size(), vector<int>(pairs.size(), -1));
        doit(0, 0, pairs.size(), pairs);
        return mx;
    }
};

// Greedy approach
class Solution
{
public:
    static bool cmp(vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int curr = INT_MIN, ans = 0;
        for (auto pair : pairs)
            if (pair[0] > curr)
                ans++, curr = pair[1];
        return ans;
    }
};