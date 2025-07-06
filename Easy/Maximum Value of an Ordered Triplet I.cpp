// Jordaar Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(1)
// The code is a brute force solution to find the maximum value of an ordered triplet in a given array.
// It uses three nested loops to iterate through all possible triplets
// in the array and calculates the value of each triplet using the formula (nums[i] - nums[j]) * nums[k].

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int len = nums.size();
        long long int ans = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                for (int k = j + 1; k < len; k++)
                {
                    long long curr = nums[i] - nums[j];
                    curr *= nums[k];
                    ans = max(ans, curr);
                }
        return ans;
    }
};
// Approach 2: Optimized Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
// The code uses two auxiliary arrays to store the maximum values to the left and right of each element in the array.

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> maxToLeft(n);
        maxToLeft[0] = nums[0];
        for (int i = 1; i < n; i++)
            maxToLeft[i] = max(maxToLeft[i - 1], nums[i]);
        vector<int> maxToRight(n);
        maxToRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            maxToRight[i] = max(maxToRight[i + 1], nums[i]);
        long long result = 0;
        for (int j = 1; j < n - 1; j++)
        {
            long long value = maxToLeft[j - 1] - nums[j];
            value *= maxToRight[j + 1];
            result = max(result, value);
        }
        return result;
    }
};