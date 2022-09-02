class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        ios_base::sync_with_stdio(false);
        if (n <= 0)
            return false;
        double x = log10(n) / log10(3);         // Get log at any base using log10(number)/log(base)
        return (x == floor(x));
    }
};