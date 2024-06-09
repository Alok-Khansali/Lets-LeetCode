// Approach 1 : Hash Table
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int a[1001] = {0}, ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                if (a[-nums[i]] > 0)
                    ans = max(ans, -nums[i]);
                else
                    a[-nums[i]] = -1;
            }
            else
            {
                if (a[nums[i]] < 0)
                    ans = max(ans, nums[i]);
                else
                    a[nums[i]] = 1;
            }
        }
        return ans;
    }
};
// Approach 2 : Sort and two pointers
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (abs(nums[i]) == abs(nums[j]) && nums[i] != nums[j])
                return abs(nums[j]);
            if (abs(nums[i]) < abs(nums[j]))
                j--;
            else
                i++;
        }
        return -1;
    }
};
// Enhanced Approach 2 - 9ms 96% faster
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j && nums[i] < 0 && nums[j] > 0)
        {
            if (abs(nums[i]) == abs(nums[j]))
                return nums[j];
            if (abs(nums[i]) < nums[j])
                j--;
            else
                i++;
        }
        return -1;
    }
};