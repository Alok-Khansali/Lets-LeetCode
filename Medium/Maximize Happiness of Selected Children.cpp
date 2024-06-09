class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end()); // Sort the happiness values in ascending order
        long long totalHappiness = 0, happinessReduced = 0, len = happiness.size();

        // Traverse the sorted happiness values in reverse order
        for (int i = len - 1; k > 0; i--, k--)
        {
            // If reducing the happiness value by the current track value makes it non-positive, return the total happiness
            if (happiness[i] - happinessReduced <= 0)
                return totalHappiness;
            totalHappiness += happiness[i] - happinessReduced; // Add the current maximum happiness value to the total
            happinessReduced++;                                // Increment the track value
        }

        return totalHappiness; // Return the total maximum happiness sum
    }
};