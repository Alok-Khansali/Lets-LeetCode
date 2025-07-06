// Draft 1 : Modular Exponentiation
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Straight up the best solution in town

class Solution
{
public:
    int mod = 1e9 + 7;
    long long power(long long x, long long exp)
    {
        long long result = 1;
        x %= mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                result = (result * x) % mod;
            x = (x * x) % mod;
            exp >>= 1;
        }
        return result;
    }
    int countGoodNumbers(long long n)
    {
        long long four = n / 2, five = (n + 1) / 2;
        ;
        long long fv = power(5, five);
        long long fr = power(4, four);
        return (fv * fr) % mod;
    }
};