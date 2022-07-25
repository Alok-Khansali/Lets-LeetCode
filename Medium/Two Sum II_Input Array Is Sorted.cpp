class Solution // The Two Pointer Approach
{              // Runtime: 25 ms, faster than 22.68% of C++ online submissions for Two Sum II - Input Array Is Sorted.
  // Memory Usage: 15.7 MB, less than 44.00% of C++ online submissions for Two Sum II - Input Array Is Sorted.
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int x = 0, y = nums.size() - 1;
        while (x < y)
        {
            if (target == nums[x] + nums[y]) // Utilising the fact that array is sorted
                return {1 + x, 1 + y};
            else if (target > nums[x] + nums[y]) // If sum is less than target, increase x;
                ++x;
            else // If sum is larger than target, decrement j
                --y;
        }
        return {};
    }
};

// Approach 2
// The Binary Search
class Solution // Runtime: 4 ms, faster than 99.59% of C++ online submissions for Two Sum II - Input Array Is Sorted.
               // Memory Usage: 15.6 MB, less than 75.27% of C++ online submissions for Two Sum II - Input Array Is Sorted.
{
public:
    vector<int> twoSum(vector<int> &n, int t)
    {
        vector<int> v(2, 0);
        for (int i = 0; i < n.size(); i++)
            if (binary_search(n.begin() + i + 1, n.end(), t - n[i]))
            {
                v[0] = i + 1, v[1] = lower_bound(n.begin() + i + 1, n.end(), t - n[i]) - n.begin() + 1;
                break;
            }
        return (v);
    }
};