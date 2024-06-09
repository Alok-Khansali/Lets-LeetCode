// Approach 1 : Two Pass
// two pass Solution
// Idea here is to take the area between subarrays with K different integers and
// Subarrays with K - 1, different integers
class Solution
{
public:
    // Function to calculate the number of subarrays with at most k distinct elements
    int subarraysWithAtMostKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequencyMap;
        int left = 0, right = 0, length = nums.size(), count = 0;
        // Slide the window from left to right
        for (right = 0; right < length; right++)
        {
            // Add the current element to the frequency map
            frequencyMap[nums[right]]++;
            // Shrink the window from the left until there are at most k distinct elements
            while (left <= right && frequencyMap.size() > k)
            {
                frequencyMap[nums[left]]--;
                if (frequencyMap[nums[left]] == 0)
                    frequencyMap.erase(nums[left]);
                left++;
            }
            // Increment the count by the number of subarrays ending at the current index
            count += right - left + 1;
        }
        return count;
    }
    // Function to calculate the number of subarrays with exactly k distinct elements
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // Calculate the number of subarrays with at most k distinct elements
        int countAtMostK = subarraysWithAtMostKDistinct(nums, k);
        // Calculate the number of subarrays with at most k-1 distinct elements
        int countAtMostKMinusOne = subarraysWithAtMostKDistinct(nums, k - 1);
        // Return the difference to get the count of subarrays with exactly k distinct elements
        return countAtMostK - countAtMostKMinusOne;
    }
};
// Approach 2 : One Pass, 96% faster
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // Array to store the count of distinct values encountered
        int distinctCount[nums.size() + 1];
        memset(distinctCount, 0, sizeof(distinctCount));
        int totalCount = 0, left = 0, right = 0, currCount = 0;
        while (right < nums.size())
        {
            // Increment the count of the current element in the window
            if (distinctCount[nums[right]] == 0)
                // If encountering a new distinct element, decrement K
                k--;
            distinctCount[nums[right++]]++;
            // If K becomes negative, adjust the window from the left
            if (k < 0)
            {
                // Move the left pointer until the count of distinct elements
                // becomes valid again
                --distinctCount[nums[left++]];
                k++;
                currCount = 0;
            }
            // If K becomes zero, calculate subarrays
            if (k == 0)
            {
                // While the count of left remains greater than 1, keep
                // shrinking the window from the left
                while (distinctCount[nums[left]] > 1)
                {
                    --distinctCount[nums[left++]];
                    currCount++;
                }
                // Add the count of subarrays with k distinct elements to the
                // total count
                totalCount += (currCount + 1);
            }
        }
        return totalCount;
    }
};