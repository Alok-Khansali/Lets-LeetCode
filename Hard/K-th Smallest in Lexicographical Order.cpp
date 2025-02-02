// Approach 1 : O(N) -> BruteForce
// Doesnt really work as per the time constraints
class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int currentNumber = 1;
        // Generate numbers from 1 to n
        for (int i = 0; i < k; ++i)
        {
            if (i == k - 1)
                return currentNumber;
            // If multiplying the current number by 10 is within the limit, do it
            if (currentNumber * 10 <= n)
                currentNumber *= 10;
            else
            {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n)
                    currentNumber /= 10; // Remove the last digit
                currentNumber += 1;      // Increment the number
            }
        }
        return 1;
    }
};
// Approach 2 : trie
class Solution
{
public:
    long getGap(long a, long b, long n)
    {
        long gap = 0;
        while (a <= n)
        {
            gap += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }
    int findKthNumber(long n, int k)
    {
        long currNum = 1;
        for (int i = 1; i < k;)
        {
            long gap = getGap(currNum, currNum + 1, n);
            if (i + gap <= k)
                i += gap, ++currNum;
            else
                ++i, currNum *= 10;
        }
        return currNum;
    }
};