// First Draft: Three pass
// time complexity: O(n)
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size(), index = 0;
        vector<int> result(n);
        // Add elements smaller than pivot
        for (int num : nums)
            if (num < pivot)
                result[index++] = num;
        // Add elements equal to pivot
        for (int num : nums)
            if (num == pivot)
                result[index++] = num;
        // Add elements greater than pivot
        for (int num : nums)
            if (num > pivot)
                result[index++] = num;
        return result;
    }
};
// Second Draft: Similiar approach
// Time complexity: O(n)
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> smaller, equal, greater;

        // Categorize elements into three groups
        for (int num : nums)
        {
            if (num < pivot)
                smaller.push_back(num);
            else if (num == pivot)
                equal.push_back(num);
            else
                greater.push_back(num);
        }
        // Combine results
        vector<int> result;
        result.reserve(nums.size()); // Optimize memory allocation
        result.insert(result.end(), smaller.begin(), smaller.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());
        return result;
    }
};
// Third Draft: Two Pointer Approach
// Time complexity: O(n)
// Space complexity: O(1)
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> result(nums.size());
        int leftIndex = 0, rightIndex = nums.size() - 1;
        // Traverse from both ends to place smaller and larger elements
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--)
        {
            if (nums[i] < pivot)
                result[leftIndex++] = nums[i];
            if (nums[j] > pivot)
                result[rightIndex--] = nums[j];
        }
        // Fill pivot elements in between
        while (leftIndex <= rightIndex)
            result[leftIndex++] = pivot;
        return result;
    }
};
