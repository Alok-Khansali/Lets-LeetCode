class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0); // Speed up I/O operations
        long long int requiredOdds = k, totalSubarrays = 0, n = nums.size(), left = 0;
        for (int i = 0; i < n; i++)
        {
            // If current number is odd, reduce the requiredOdds count
            if (nums[i] & 1)
            {
                long long int startCount = 0, endCount = 0;
                requiredOdds--;
                // When requiredOdds reaches zero, we've found a subarray with exactly k odd numbers
                if (requiredOdds == 0)
                {
                    // Count the number of even numbers to the right of current position
                    while (i + 1 < n && nums[i + 1] % 2 == 0)
                        i++, endCount++;
                    // Count the number of even numbers to the left of current position
                    while (left < n && nums[left] % 2 == 0)
                        left++, startCount++;
                    // Move the left pointer to the next position, away from the current odd number
                    left++;
                    // Increase requiredOdds to search for next subarray, since we removed the leftmost odd in the window
                    requiredOdds++;
                    // Calculate the total subarrays with k odd numbers
                    totalSubarrays += (endCount + 1) * (startCount + 1);
                }
            }
        }
        return totalSubarrays;
    }
};