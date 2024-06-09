class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int firstMin = 0;  // First smallest element in the current row
        int secondMin = 0; // Second smallest element in the current row
        int position = -1; // Position of the first smallest element in the previous row

        for (auto i = 0; i < grid.size(); ++i)
        {
            int newFirstMin = 101;  // Initialize the new first smallest element
            int newSecondMin = 101; // Initialize the new second smallest element
            int newPosition = -1;   // Initialize the new position of the first smallest element

            for (auto j = 0; j < grid[i].size(); ++j)
            {
                // Determine the minimum of the two previous smallest elements
                int minPrev = j != position ? firstMin : secondMin;

                // Calculate the new first and second smallest elements
                if (grid[i][j] + minPrev < newFirstMin)
                {
                    newSecondMin = newFirstMin;
                    newFirstMin = grid[i][j] + minPrev;
                    newPosition = j;
                }
                else
                {
                    newSecondMin = min(newSecondMin, grid[i][j] + minPrev);
                }
            }

            // Update the first and second smallest elements and their positions for the next row
            firstMin = newFirstMin;
            secondMin = newSecondMin;
            position = newPosition;
        }

        // Return the minimum falling path sum from the first row
        return firstMin;
    }
};