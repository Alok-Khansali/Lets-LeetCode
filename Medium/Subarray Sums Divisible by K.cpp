class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // Array to store the frequency of remainders
        int remainderCount[k];
        // Initialize the remainders array with 0
        memset(remainderCount, 0, sizeof(remainderCount));
        int currentRemainder = 0; // Current prefix sum remainder
        int subarrayCount = 0;    // Count of subarrays divisible by k
        remainderCount[0] = 1;    // There is one way to have a remainder of 0 (empty subarray)
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Update the current remainder by adding the current number and taking modulo k
            // Adding k before taking modulo k ensures we handle negative numbers correctly
            currentRemainder = ((currentRemainder + nums[i] % k) + k) % k;
            // Add the number of times this remainder has occurred before to the count
            subarrayCount += remainderCount[currentRemainder];
            // Increment the frequency of the current remainder
            remainderCount[currentRemainder]++;
        }
        return subarrayCount;
    }
};
