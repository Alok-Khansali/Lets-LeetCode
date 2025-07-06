// 100% faster solution for C++
// Approach : Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        // freqTable keeps track of how many times each number (0-100) appears.
        int freqTable[101] = {0};
        int index = 0;         // Pointer to track position in the array
        int len = nums.size(); // Length of the input array
        int ans = 0;           // Result: count of operations required

        for (int j = 0; j < len; j++)
        {
            // If the current number has already been seen before
            // (its frequency is non-zero), perform an operation
            while (freqTable[nums[j]] > 0)
            {
                int i = index; // Save the current index to set a boundary
                ans++;         // One operation is needed here
                // In this operation, we "reset" frequencies of a subarray of size up to 3
                // (from current index to index+2 or end of array, whichever is smaller)
                // It is possible that we might exceed the current index and reset the element that has not been visited yet
                // But its not a problem because we have to remove 3 or less element if the duplicate is found
                // So we can reset the frequency of the current element and the next two elements
                // And they wont be visited again because we dont check if the frequency is negative
                for (; index <= min(i + 2, len - 1); index++)
                    freqTable[nums[index]]--;
            }
            // Mark the current number as seen
            freqTable[nums[j]] += 1;
        }

        return ans; // Return total operations needed
    }
};
