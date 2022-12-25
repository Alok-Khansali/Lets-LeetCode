class Solution // A positive number
{              // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Ugly Number.
               // Memory Usage: 5.9 MB, less than 69.56% of C++ online submissions for Ugly Number.
public:
    bool isUgly(int n)
    {
        if (n == 0)
            return false;
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        return (n == 1);
    }
};