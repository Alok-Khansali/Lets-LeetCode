class Solution // Runtime: 2 ms, faster than 98.28% of C++ online submissions for Bag of Tokens.
// Memory Usage: 10.6 MB, less than 66.86% of C++ online submissions for Bag of Tokens.
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        ios_base::sync_with_stdio(0);
        // Sorting is very important
        sort(tokens.begin(), tokens.end());
        // Two pointer things
        int i = 0, j = tokens.size() - 1, ans = 0, c = 0;
        while (i <= j)
        {
            // If power is less
            if (tokens[i] > power)
            {
                // if c > 0, add the last unused maximum token available
                if (c > 0 && (power + tokens[j] >= tokens[i]))
                {
                    --c;                // Decrease c
                    power += tokens[j]; // Raise power
                    --j;                // Current highest token used, go left
                }
                else // No more moves can be made, return the answer
                    return ans;
            }
            else // Power is more just subtract from the power and raise the counter c
            {
                ++c;                // Raise the counter
                ans = max(c, ans);  // Get the maximum
                power -= tokens[i]; // Decrease the power
                i++;                // Go right
            }
        }
        return ans;
    }
};