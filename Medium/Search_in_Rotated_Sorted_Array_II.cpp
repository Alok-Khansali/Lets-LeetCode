class Solution // Linear Search
{              // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array II.
               // Memory Usage: 14 MB, less than 71.85% of C++ online submissions for Search in Rotated Sorted Array II.
public:
    bool search(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for (int i : nums)
        {
            if (i == target)
                return true;
        }
        return false;
    }
};
// Using STL
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        return (count(nums.begin(), nums.end(), target));
    }
};
// Using Binary Search
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int st = 0, end = nums.size() - 1;
        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (nums[mid] == target || nums[st] == target || nums[end] == target)
                return true;
            if (nums[st] == nums[end]) // Same means move on
            {
                st++;
                continue;
            }
            if (nums[st] <= nums[mid])
            {
                if (nums[st] <= target and target <= nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            else if (nums[mid] <= target and target <= nums[end])
                st = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};