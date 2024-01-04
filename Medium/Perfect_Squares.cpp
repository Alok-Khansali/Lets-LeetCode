// BFS
// Runtime: 186 ms, faster than 80.32% of C++ online submissions for Perfect Squares.
// Memory Usage: 39 MB, less than 14.00% of C++ online submissions for Perfect Squares.
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> arr, st(int(1e4) + 1, -1);
        int a = 1;
        while (a * a <= n)
        {
            arr.push_back(a * a);
            a++;
        }
        queue<int> q;
        st[0] = 0;
        q.push(0);
        int level = 0;
        while (q.size() > 0)
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                int top = q.front();
                q.pop();
                if (top == n)
                    return level;
                for (auto x : arr)
                {
                    int cur = x + top;
                    if (cur <= n && st[cur] == -1)
                    {
                        st[cur] = 0;
                        q.push(cur);
                    }
                }
            }
            level++;
        }
        return level;
    }
};

// DP
class Solution
{
public:
    int numSquares(int n)
    {
        // vector for updating the dp array/values
        vector<int> dp(n + 1, INT_MAX);
        // base case
        dp[0] = 0;
        int count = 1;
        while (count * count <= n)
        {
            int sq = count * count;
            for (int i = sq; i < n + 1; i++)
                dp[i] = min(dp[i - sq] + 1, dp[i]);
            count++;
        }
        return dp[n];
    }
};