class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long totalSubarrays = 0;
        unordered_map<int, int> frequency;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            // When adding nums[right], it forms `frequency[nums[right]]` new pairs
            k -= frequency[nums[right]]++;
            // Shrink the window from the left if pair limit exceeded
            while (k <= 0)
                k += --frequency[nums[left++]];
            // All subarrays ending at `right` and starting from index 0 to `left - 1` are valid
            totalSubarrays += left;
        }
        return totalSubarrays;
    }
};