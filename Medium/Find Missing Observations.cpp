// 97.79% faster
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        ios_base::sync_with_stdio(0);       // Speeds up I/O operations (not crucial for the logic)
        long long int x = rolls.size() + n; // Total number of rolls (given + missing)
        long long int total = mean * x;     // The total sum required to achieve the mean
        // Subtract the sum of existing rolls from the total required sum
        for (int i : rolls)
            total -= i;
        // Calculate the average value needed for each missing roll
        double averageNeeded = (double)(total) / (double)(n);
        // If the average needed is outside the valid range of a dice roll, return an empty array
        if (averageNeeded > 6 || averageNeeded < 1)
            return {};
        vector<int> result(n);
        int baseValue = total / n; // The base value each missing roll should have
        int remainder = total % n; // The remaining value that needs to be distributed
        // Distribute the values across the missing rolls
        for (int i = 0; i < n; i++)
        {
            result[i] = baseValue + (i < remainder);
        }
        return result;
    }
};