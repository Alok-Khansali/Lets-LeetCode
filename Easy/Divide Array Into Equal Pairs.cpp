// First Draft using the frequency array
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        // Frequency array to store the frequency of each element
        int freq[501] = {0};
        // Counting the frequency of each element
        for (int i : nums)
            freq[i]++;
        // Checking if the frequency of each element is even
        // If not, return false
        for (int i = 1; i < 501; i++)
            if (freq[i] & 1)
                return false;
        return true;
    }
};