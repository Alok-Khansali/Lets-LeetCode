class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0);
        int start = 0, end = 0, maxLength = 0, n = nums.size();
        unordered_map<int, int> mp; // Map to store prefix sum frequencies
        // Iterate through the array
        while (end >= start && end < n)
        {
            int current = nums[end];
            // Update the frequency of the current prefix sum
            mp[current]++;

            // If the frequency of a prefix sum exceeds k, move the start pointer until it satisfies the condition
            if (mp[current] > k)
            {
                while (nums[start] != current)
                    mp[nums[start++]]--;

                mp[nums[start++]]--;
            }
            // Update the maximum length of the subarray
            maxLength = max(maxLength, end - start + 1);
            end++;
        }
        return maxLength; // Return the maximum length of the subarray
    }
};