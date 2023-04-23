#define mod 1000000007
#define lli long long int
class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        int n = s.length();
        if (s[0] == '0')
            return 0;
        vector<lli> dp(n, 0);
        int K = to_string(k).length();
        for (int i = 0; i < n; i++)
        {
            lli curr = 0, mul = 1;
            for (int j = i; j > 0 && i - j <= K; j--)
            {
                curr = (s[j] - '0') * mul + curr;
                if (curr > k)
                    break;
                mul *= 10;
                if (s[j] != '0')
                    dp[i] = (dp[i] + dp[j - 1]) % mod;
            }
            if (curr < k)
            {
                curr = (s[0] - '0') * mul + curr;
                if (curr <= k)
                    dp[i] = (dp[i] + 1) % mod;
            }
        }
        return dp[n - 1];
    }
};