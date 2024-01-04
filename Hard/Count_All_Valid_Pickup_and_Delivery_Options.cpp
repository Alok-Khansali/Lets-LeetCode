class Solution
{
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
    // Memory Usage: 5.9 MB, less than 53.14% of C++ online submissions for Count All Valid Pickup and Delivery Options.
public:
    int countOrders(int n)
    {
        long long int ans = 1, m = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
        {
            ans *= i * (2 * i - 1); // Combinations
            ans %= m;
        }
        return ans;
    }
};