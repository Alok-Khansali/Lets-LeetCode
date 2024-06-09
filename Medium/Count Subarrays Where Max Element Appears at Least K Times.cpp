class Solution
{
public:
    long long countSubarrays(std::vector<int> &nums, int k)
    {
        long long subarrayCount = 0;                             // Variable to store the result
        long long maxElementCount = 0;                           // Frequency of the maximum element encountered so far
        int arraySize = nums.size();                             // Size of the input array
        int maxElement = *max_element(nums.begin(), nums.end()); // Maximum element in the array
        int windowStart = 0;                                     // Start index of the sliding window

        // Iterate through the array
        for (int i = 0; i < arraySize; i++)
        {
            // If the current element is the maximum element encountered so far
            if (nums[i] == maxElement)
            {
                maxElementCount++; // Increment the frequency of the maximum element

                // If the frequency of the maximum element reaches the target count
                if (maxElementCount == k)
                {
                    long long subarraysWithMax = arraySize - i; // Number of subarrays with the maximum element occuring atleast K
                    // Move the start pointer until it encounters a different element
                    while (nums[windowStart] != maxElement)
                    {
                        windowStart++;
                        subarrayCount += subarraysWithMax; // Increment the count by the number of subarrays with the maximum element
                    }
                    subarrayCount += subarraysWithMax; // Increment the count by the number of subarrays with the maximum element
                    windowStart++;                     // Move the start pointer to the next index
                    maxElementCount--;                 // Decrease the frequency of the maximum element
                }
            }
        }

        return subarrayCount; // Return the result
    }
};
