class Solution
{ // Runtime: 44 ms, faster than 85.43% of C++ online submissions for Largest Perimeter Triangle.
  // Memory Usage: 22 MB, less than 22.88% of C++ online submissions for Largest Perimeter Triangle.
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--)
            if (nums[i - 1] + nums[i - 2] > nums[i]) // Just the property on triangle i read in 8th class
                return (nums[i] + nums[i - 1] + nums[i - 2]);
        return 0;
    }
};