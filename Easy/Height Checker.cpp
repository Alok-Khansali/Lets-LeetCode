// Approach 1 : using only O(N) time
// 100% faster
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        ios_base::sync_with_stdio(0);
        int result = 0;           // To count the number of heights out of order
        int currentHeight = 0;    // To track the current height index in the frequency array
        int frequency[101] = {0}; // Frequency array to count occurrences of each height (0-100)
        // Fill the frequency array with the counts of each height
        for (int height : heights)
        {
            frequency[height]++;
        }
        // Iterate through the original heights array
        for (int height : heights)
        {
            // Find the next non-zero frequency in the frequency array
            while (frequency[currentHeight] == 0)
            {
                currentHeight++;
            }
            // If the current height does not match the sorted height (currentHeight), increment the result
            if (currentHeight != height)
            {
                result++;
            }
            // Decrement the frequency of the current height
            frequency[currentHeight]--;
        }

        return result;
    }
};
// Approach 2 : using sort
// 100% faster
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        ios_base::sync_with_stdio(0);
        int ans = 0;
        vector<int> v = heights;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            ans += v[i] != heights[i];
        return ans;
    }
};