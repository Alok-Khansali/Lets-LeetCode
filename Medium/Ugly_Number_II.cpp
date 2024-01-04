class Solution
{ // Runtime: 19 ms, faster than 57.62% of C++ online submissions for Ugly Number II.
  // Memory Usage: 7.8 MB, less than 41.27% of C++ online submissions for Ugly Number II.
public:
    int nthUglyNumber(int n)
    {
        ios_base::sync_with_stdio(0);
        long long int a = 0, b = 0, c = 0;
        vector<int> ugly(n, 1);
        for (int i = 1; i < n; i++)
        {
            ugly[i] = (min({ugly[a] * 2, ugly[b] * 3, ugly[c] * 5}));
            if (ugly[i] == ugly[a] * 2)
                ++a;
            if (ugly[i] == ugly[b] * 3)
                ++b;
            if (ugly[i] == ugly[c] * 5)
                ++c;
        }
        return ugly[n - 1];
    }
};