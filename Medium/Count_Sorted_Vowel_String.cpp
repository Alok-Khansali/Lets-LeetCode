class Solution // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Sorted Vowel Strings.
               // Memory Usage: 5.9 MB, less than 85.48% of C++ online submissions for Count Sorted Vowel Strings.
{
public: // Math in Style
    int countVowelStrings(int n)
    {
        // a[0] = 1, constant always
        // a[1] = n, always
        // a[2] = sum of first n terms = (n * (n+1))/2
        // a[3] = [ n * (n + 1) * (n + 2) ]/ 6
        // a[4] = [n * (n + 1) * (n + 2) * (n + 4)]/ 24 = [n^4 + 6*(n^3) + 11*(n^2) + 6*n]/24

        // a[4] stores the answer of the (i - 1)th iteration,
        // So the value of a[4] at (i+1)th iteration will be the answer for the (i)th iteration
        n += 1;
        return (n * n * (n * n + 6 * n + 11) + 6 * n) / 24;
    }
};
/*
class Solution
{
public:
    int countVowelStrings(int n)
    {
        int a[5] = {1, 1, 1, 1, 1}, sum = 5; // Prepare a Dp array, set all 5 values to 1 ({a,e,i,o,u})
        while (n > 1)                        // Sum Stores the final answer
        {
            for (int i = 4; i >= 0; i--)
            {
                int x = a[i];
                a[i] = sum;
                sum -= x;
            }
            for (int i = 0; i < 5; i++)
                sum += a[i];
            --n;
        }
        return sum;
    }
};
*/