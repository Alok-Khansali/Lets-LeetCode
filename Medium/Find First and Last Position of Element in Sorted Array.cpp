class Solution // Runtime: 8 ms, faster than 84.21% of C++ online submissions for Find First and Last Position of Element in Sorted Array
// Memory Usage: 13.7 MB, less than 63.15% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        // The Binary Search
        while (i <= j)
        {
            // Prevents the overflow
            int m = i + (j - i) / 2;
            // If found
            if (nums[m] == target)
            {
                int x = m + 1;
                while (x <= j && nums[x] == target)
                    x++;
                while (m >= 0 && nums[m] == target)
                    m--;
                // return the vector
                return {m + 1, x - 1};
            }
            else if (nums[m] < target)
                i = m + 1;
            else
                j = m - 1;
        }
        return {-1, -1};
    }
};