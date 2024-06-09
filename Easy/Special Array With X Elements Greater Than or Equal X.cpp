// Approach 1 : O(N log N) time and O(N) space
// Simple idea here is to sort the values
// Get return a value if a value == length of array - current index
// Any number greater that length of array is useless, hence no need to traverse beyond that
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int r = 0, n = nums.size();
        for (int i = 0; i < n && r <= n - i; i++)
        {
            while (r <= nums[i] && r <= n - i)
            {
                if (r == n - i)
                    return r;
                r++;
            }
        }
        return -1;
    }
};
// Approach 2 : O(N) time and space
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> freq(N + 1, 0);
        for (int i = 0; i < N; i++)
            freq[min(N, nums[i])]++;
        int numGreaterThanOrEqual = 0;
        for (int i = N; i >= 1; i--)
        {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual)
                return i;
        }
        return -1;
    }
};