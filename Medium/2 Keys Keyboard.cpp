// 100% fast
// Almost Brute Force
class Solution
{
public:
    int minSteps(int n)
    {
        ios_base::sync_with_stdio(0);
        vector<int> dp(n + 1, n + 3);
        dp[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            // copy ops
            int copy = dp[i] + 1;
            for (int j = i * 2; j <= n; j += i)
            {
                // paste ops
                int paste = ++copy;
                dp[j] = min(paste, dp[j]);
            }
        }
        return dp[n];
    }
};
// Approach 2
// Prime Factorisation
class Solution
{
public:
    int minSteps(int n)
    {
        int ans = 0;
        int d = 2;
        while (n > 1)
        {
            // If d is prime factor, keep dividing
            // n by d until is no longer divisible
            while (n % d == 0)
            {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};