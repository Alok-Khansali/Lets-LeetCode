
class Solution
{
public:
    bool judgeSquareSum(int target)
    {
        if (target <= 2)
            return true; // Early return for small values of target

        // Iterate from the square root of target down to 1
        for (int a = sqrt(target); a >= 1; a--)
        {
            // Calculate the remaining value after subtracting the square of a
            int remainder = target - a * a;
            // Calculate the integer square root of the remainder
            int b = sqrt(remainder);

            // Check if the square of b equals the remainder
            if (b * b == remainder)
                return true; // If true, a^2 + b^2 = target, return true
        }

        // If no pair (a, b) is found such that a^2 + b^2 = target, return false
        return false;
    }
};

// two pointer
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c <= 2)
            return true;
        int a = sqrt(c), b = 0;
        while (b <= a)
        {
            long long int sum = pow(a, 2) + pow(b, 2);
            if (c == sum)
                return true;
            if (sum < c)
                b++;
            else
                a--;
        }
        return false;
    }
};