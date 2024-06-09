// 98.94% better speed,  99.47% better space
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        ios_base::sync_with_stdio(0);
        // Initialize variables to track indices and subarray count
        int leftIndex = -1, rightIndex = -1, nonInRangeIndex = -1, length = nums.size();
        long long subarrayCount = 0;
        // Iterate through the array
        for (int i = 0; i < length; i++)
        {
            // Check if the current element is out of range
            if (nums[i] < minK || nums[i] > maxK)
                nonInRangeIndex = i;
            // Check if the current element is equal to minK
            if (nums[i] == minK)
                leftIndex = i;
            // Check if the current element is equal to maxK
            if (nums[i] == maxK)
                rightIndex = i;
            // Update the subarray count with the count of valid subarrays
            subarrayCount += (max(0, min(leftIndex, rightIndex) - nonInRangeIndex));
        }
        // Return the final subarray count
        return subarrayCount;
    }
};
