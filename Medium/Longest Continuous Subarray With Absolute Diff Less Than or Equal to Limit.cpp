class Solution // Multiset
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0); // Speed up I/O operations
        long long int requiredOdds = k, n = nums.size();
        long long int left = 0, totalSubarrays = 0;
        // Iterate through the array to find subarrays with exactly k odd numbers
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
                    // Move the left pointer to the next position
                    left++;
                    // Increase requiredOdds to search for next subarray
                    requiredOdds++;
                    // Calculate the total subarrays with k odd numbers
                    totalSubarrays += (endCount + 1) * (startCount + 1);
                }
            }
        }
        return totalSubarrays;
    }
};
// Approach 2 Dequeue
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> maxDeque, minDeque; // Deques to keep track of the max and min elements in the current window
        int start = 0, maxLength = 0;  // start is the starting index of the current window, maxLength stores the maximum length of valid subarray
        for (int end = 0; end < nums.size(); end++)
        {
            // Maintain the decreasing order in maxDeque
            while (!maxDeque.empty() && maxDeque.back() < nums[end])
                maxDeque.pop_back();
            maxDeque.push_back(nums[end]);
            // Maintain the increasing order in minDeque
            while (!minDeque.empty() && minDeque.back() > nums[end])
                minDeque.pop_back();
            minDeque.push_back(nums[end]);
            // Ensure the difference between the maximum and minimum elements in the window does not exceed the limit
            while (maxDeque.front() - minDeque.front() > limit)
            {
                // If the element to be removed is the front element of maxDeque or minDeque, remove it
                if (maxDeque.front() == nums[start])
                    maxDeque.pop_front();
                if (minDeque.front() == nums[start])
                    minDeque.pop_front();
                ++start; // Move the start index to the right to shrink the window
            }
            // Calculate the maximum length of the subarray
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};