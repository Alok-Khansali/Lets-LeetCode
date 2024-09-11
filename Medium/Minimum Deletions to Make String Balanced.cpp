// Approach 1
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int minDeletions = INT_MAX; // To keep track of the minimum deletions required
        int length = s.size();
        int bCount = 0;                          // To count 'b' characters from the start
        int aCount = 0;                          // To count 'a' characters from the end
        vector<int> bPrefixCount(length + 1, 0); // To store the prefix count of 'b'
        vector<int> aSuffixCount(length + 1, 0); // To store the suffix count of 'a'
        // Calculate prefix count of 'b'
        for (int i = 0; i < length; i++)
        {
            bPrefixCount[i] = bCount;
            if (s[i] == 'b')
            {
                bCount++;
            }
        }
        // Calculate suffix count of 'a'
        for (int i = length - 1; i >= 0; i--)
        {
            if (s[i] == 'a')
                aCount++;
            aSuffixCount[i] = aCount;
        }
        // Adjust counts for the first 'a' and last 'b'
        aCount -= s[0] == 'a';
        bCount -= s[length - 1] == 'b';
        // Calculate the minimum deletions
        minDeletions = min(aCount, bCount);
        for (int i = 0; i < length; i++)
            if (s[i] == 'b')
                minDeletions = min(minDeletions, bPrefixCount[i] + aSuffixCount[i]);

        return minDeletions;
    }
};

// approach 2
//  optimum dp
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;

        // min_deletions variable represents dp[i]
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                b_count++;
            }
            else
            {
                // Two cases: remove 'a' or keep 'a'
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};
// approach 3
//  stack
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.length();
        stack<char> charStack;
        int deleteCount = 0;

        // Iterate through each character in the string
        for (int i = 0; i < n; i++)
        {
            // If stack is not empty, top of stack is 'b',
            // and current char is 'a'
            if (!charStack.empty() && charStack.top() == 'b' && s[i] == 'a')
            {
                charStack.pop(); // Remove 'b' from stack
                deleteCount++;   // Increment deletion count
            }
            else
            {
                charStack.push(s[i]); // Push current character onto stack
            }
        }

        return deleteCount;
    }
};