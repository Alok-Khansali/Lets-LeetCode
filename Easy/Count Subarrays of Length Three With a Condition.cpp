// Approach 1 : simple brute force
// Time Complexity : O(n)
// Space Complexity : O(1)
// Highly space efficient solution
class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 2; ++i)
            // Check if middle element is even
            if (nums[i + 1] % 2 == 0)
                // Check if the sum of first and third equals half of the middle
                if (nums[i] + nums[i + 2] == nums[i + 1] / 2)
                    ++count;
        return count;
    }
};

// Approach 2
class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 2; ++i)
            // Compare by converting to float to avoid integer division
            if (static_cast<float>(nums[i] + nums[i + 2]) == static_cast<float>(nums[i + 1]) / 2.0f)
                ++count;
        return count;
    }
};
// Approach 3 : No implicit conversion
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 2; ++i)
            // Compare by converting to float to avoid integer division
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
                ++count;
        return count;
    }
};