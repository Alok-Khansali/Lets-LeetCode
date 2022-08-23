class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (n == 0)
            return false;
        double b = log2(n) / 2;
        return (b == round(b));
    }
};

// Approach 2
class Solution
{ // Runtime: 5 ms, faster than 23.39% of C++ online submissions for Power of Four.
  // Memory Usage: 5.9 MB, less than 71.30% of C++ online submissions for Power of Four.
public:
    bool isPowerOfFour(int n)
    {
        while (n > 1 && n % 4 == 0)
            n /= 4;
        return (n == 1);
    }
};