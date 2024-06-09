// Approach 1 : making an visited array to check the values that have been in the array
// TC : O(N), SC : O(N)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int len = nums.size();
        int a[len + 5];
        memset(a, 0, sizeof(a));
        for (int i : nums)
        {
            if (i < 0 || i > len)
                continue;
            a[i] = 1;
        }
        for (int i = 1; i <= len + 4; i++)
            if (a[i] == 0)
                return i;
        return 0;
    }
};
// Approach 2 : Cycle sort
// TC : O(N), SC : O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size(), i = 0;
        // Use cycle sort to place positive elements smaller than n
        // at the correct index
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        // Iterate through nums
        // return smallest missing positive integer
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        // If all elements are at the correct index
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};