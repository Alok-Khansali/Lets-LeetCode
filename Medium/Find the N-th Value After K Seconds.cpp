class Solution
{
public:
    int valueAfterKSeconds(int n, int k)
    {
        // Initialize a vector of size n with all elements set to 1
        vector<long long int> values(n, 1);
        long long int mod = 1e9 + 7;

        // Loop for k seconds
        for (int second = 0; second < k; second++)
        {
            // Update the values in the vector based on the previous values
            for (int index = 1; index < n; index++)
            {
                values[index] = (values[index] + values[index - 1]) % mod;
            }
        }
        // Return the N-th value after K seconds
        return values[n - 1];
    }
};