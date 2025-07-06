// Bruce Force Solution
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> result;
        int n = nums.size();
        int marked[1001] = {0}; // Array to mark which indices are already added
        for (int i = 0; i < n; i++)
            if (nums[i] == key)
            {
                // For each index around the key (within distance k)
                int left = max(0, i - k);
                int right = min(n - 1, i + k);
                for (int j = left; j <= right; j++)
                    if (marked[j] == 0)
                    {
                        result.push_back(j);
                        marked[j] = 1; // Mark as added
                    }
            }
        return result;
    }
};
// Time Complexity: O(n * k), where n is the size of nums and k is the distance
// Space Complexity: O(n), for the result vector and the marked array

// Optimized Solution
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> result;
        int nextIndexToAdd = 0; // next index to consider adding
        int n = nums.size();
        for (int j = 0; j < n; ++j)
            if (nums[j] == key)
            {
                int leftBound = max(nextIndexToAdd, j - k);
                int rightBound = min(n - 1, j + k) + 1; // exclusive
                for (int i = leftBound; i < rightBound; ++i)
                    result.push_back(i);
                nextIndexToAdd = rightBound;
            }
        return result;
    }
};
// Time Complexity: O(n + m), where n is the size of nums and m is the total number of indices added
// Space Complexity: O(m), for the result vector where m is the number of indices added