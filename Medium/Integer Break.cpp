class Solution // Math Based solution 
{
public:
    int integerBreak(int n)
    {
        if (n < 4)
            return n - 1;
        int x = n % 3, y = n / 3, ans = pow(3, y);
        if (x <= 1)
            ans /= 3, ans *= (3 + x);
        else
            ans *= x;
        return ans;
    }
};
// DP Based Solution