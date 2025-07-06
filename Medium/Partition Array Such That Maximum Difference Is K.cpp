class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end()); // Sort the array

        int n = nums.size();
        int currentMin = nums[0];
        int currentMax = nums[0];
        int partitions = 1; // At least one partition is needed
        for (int i = 0; i < n; i++)
        {
            currentMin = min(currentMin, nums[i]);
            currentMax = max(currentMax, nums[i]);
            // If the current segment is valid (max - min <= k), continue expanding it
            if (currentMax - currentMin <= k)
                continue;
            // Otherwise, start a new partition
            partitions++;
            currentMin = nums[i];
            currentMax = nums[i];
        }

        return partitions;
    }
};
// Time Complexity: O(n log n) due to sorting, where n is the number of elements in nums.
// Space Complexity: O(1) for the partitioning logic, as we are using a