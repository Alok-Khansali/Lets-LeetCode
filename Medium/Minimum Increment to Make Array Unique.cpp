class Solution /// Approach 1 : Counting sort + Math
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        // Maximum possible value in the array
        const int MAX_VAL = 100000;
        // Array to count the frequency of each number in nums
        int freq[MAX_VAL + 1] = {0};
        // Variables to keep track of the maximum value in nums and the result
        int maxNum = 0, increments = 0, nextAvailable = -1;
        // Count the frequency of each number in nums
        for (int num : nums)
        {
            freq[num]++;
            maxNum = max(num, maxNum);
        }
        // Iterate over each possible number up to the maximum number in nums
        for (int num = 0; num <= maxNum; num++)
        {
            if (freq[num] != 0)
            {
                // Calculate the required increment and the frequency of the current number
                int diff = max(0, nextAvailable + 1 - num);
                int count = freq[num];
                // Calculate the total increments required to make all instances of the current number unique
                increments += diff * count + (count * (count - 1)) / 2;
                // Update the next available number to place the incremented values
                nextAvailable = max(nextAvailable + 1, num) + count - 1;
            }
        }
        return increments;
    }
};
// Sorting
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        // Sort the input array
        sort(nums.begin(), nums.end());
        int nextUnique = -1; // Variable to track the next unique number required
        int increments = 0;  // Variable to store the total increments needed
        // Iterate through the sorted array
        for (int i = 0; i < nums.size(); i++)
        {
            // If the current number is greater than or equal to the next required unique number
            if (nums[i] >= nextUnique + 1)
                nextUnique = nums[i]; // Update next unique number to the current number
            else
            {
                // Calculate the number of increments needed
                increments += (nextUnique + 1 - nums[i]);
                nextUnique++; // Move to the next required unique number
            }
        }
        return increments; // Return the total number of increments needed
    }
};
