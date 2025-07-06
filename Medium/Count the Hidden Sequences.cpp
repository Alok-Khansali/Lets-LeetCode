class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        // The idea is to build from the lowest number
        // Then see the largest value in the sequence
        // And add to answer 1 + upper - lower;
        // The answer is the number of integers in the range [lower, upper] that can be the first element of the array.
        int left = 0, right = 0, sum = 0;
        // Calculate the prefix sum of differences
        // and track the minimum and maximum values of the prefix sum
        for (int i : differences)
        {
            // Update the prefix sum
            // and adjust the left and right bounds accordingly
            sum += i;
            left = min(sum, left);
            right = max(sum, right);
            // If the current prefix sum is less than the lower bound,
            // we need to adjust the left bound to ensure the sequence is valid
            if (right - left > upper - lower)
                return 0;
        }
        return upper - lower - right + left + 1;
    }
};