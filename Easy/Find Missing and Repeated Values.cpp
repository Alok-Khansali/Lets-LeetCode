class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int frequency[2501] = {0}, gridSize = grid.size();
        vector<int> result(2, 0);
        for (auto &row : grid)
            for (int num : row)
                frequency[num]++;
        for (int num = 1; num <= gridSize * gridSize; num++)
            if (frequency[num] == 2)
                result[0] = num; // Repeated value
            else if (frequency[num] == 0)
                result[1] = num; // Missing value
        return result;
    }
};
// Time Complexity: O(N^2)
// Space Complexity: O(N)