class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int x = __gcd(a, b), ans = 0;
        for (int i = 1; i * i <= x; i++)
            if (x % i == 0)
                ans += 1 + (x / i != i);
        return ans;
    }
};