// LeetCode 384. Shuffle an Array
// Trying it out with the STL algorithm next_permutation
// Time complexity: O(n), Space complexity: O(n)
class Solution
{
public:
    vector<int> original, base;
    Solution(vector<int> &nums)
    {
        original = nums;
        base = original;
    }

    vector<int> reset()
    {
        return base;
    }

    vector<int> shuffle()
    {
        next_permutation(original.begin(), original.end());
        return original;
    }
};

// Another approach is to use the Fisher-Yates shuffle algorithm
// Time complexity: O(n), Space complexity: O(1)
class Solution
{
public:
    vector<int> original, base;
    Solution(vector<int> &nums)
    {
        original = nums;
        base = original;
    }

    vector<int> reset()
    {
        return base;
    }

    vector<int> shuffle()
    {
        for (int i = original.size() - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            swap(original[i], original[j]);
        }
        return original;
    }
};
// Fisher-Yates shuffle algorithm is a well-known algorithm for shuffling an array in place.
// It works by iterating through the array from the last element to the first, and for each element,
// it swaps it with a randomly chosen element that comes before it (including itself).
// This ensures that each possible permutation of the array is equally likely.
