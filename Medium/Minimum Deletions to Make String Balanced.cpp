// Approach 1
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int ans = INT_MAX, len = s.size(), bc = 0, ac = 0;
        int a[len + 1], b[len + 1];
        for (int i = 0; i < len; i++)
        {
            b[i] = bc;
            if (s[i] == 'b')
                bc++;
        }
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == 'a')
                ac++;
            a[i] = ac;
        }
        ac -= s[0] == 'a';
        bc -= s[len - 1] == 'b';
        ans = min(ac, bc);
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'b')
            {
                ans = min(ans, b[i] + a[i]);
            }
        }
        return ans;
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