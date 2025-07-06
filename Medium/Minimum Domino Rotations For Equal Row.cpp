// Approach 1 : Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int minDominoRotations(vector<int> &top, vector<int> &bottom)
    {
        vector<int> topCount(7), bottomCount(7), sameCount(7);
        int totalDominoes = top.size();
        // Count occurrences of each number (1 through 6) in top, bottom, and both (same)
        for (int i = 0; i < totalDominoes; ++i)
        {
            topCount[top[i]]++;
            bottomCount[bottom[i]]++;
            sameCount[top[i]] += top[i] == bottom[i];
        }
        // Try each possible value (1 to 6) to see if it can fill an entire row
        for (int num = 1; num <= 6; ++num)
            if (topCount[num] + bottomCount[num] - sameCount[num] == totalDominoes)
                // Minimum rotations needed is total minus the maximum count in either row
                return totalDominoes - max(topCount[num], bottomCount[num]);
        return -1; // No possible way to make all values equal
    }
};