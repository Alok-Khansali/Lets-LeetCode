class Solution
{
public:
    // Helper function to check if it's possible to place m balls with at least 'gap' distance apart
    bool canPlaceBalls(int gap, vector<int> &positions, int m)
    {
        int lastPosition = positions[0]; // Position of the last placed ball
        int ballsRemaining = m - 1;      // Number of balls left to place
        // Iterate over the positions to try placing the remaining balls
        for (int i = 1; i < positions.size() && ballsRemaining > 0; i++)
        {
            // Check if the current position is at least 'gap' distance from the last placed ball
            if (positions[i] - lastPosition >= gap)
            {
                ballsRemaining--;            // Place the ball
                lastPosition = positions[i]; // Update the position of the last placed ball
            }
        }
        return ballsRemaining == 0; // Return true if all balls are placed successfully
    }
    // Function to find the maximum minimum distance between any two balls
    int maxDistance(vector<int> &positions, int m)
    {
        // Sort the positions to facilitate binary search
        sort(positions.begin(), positions.end());
        int n = positions.size();
        // Initialize the binary search range
        int left = 1;                                // Minimum possible gap
        int right = positions[n - 1] - positions[0]; // Maximum possible gap
        int maxMinDistance = -1;
        // Perform binary search
        while (left <= right)
        {
            int mid = (left + right) / 2;

            // Check if it's possible to place all balls with at least 'mid' distance apart
            if (canPlaceBalls(mid, positions, m))
            {
                maxMinDistance = mid; // Update the result
                left = mid + 1;       // Try for a larger gap
            }
            else
                right = mid - 1; // Try for a smaller gap
        }
        return maxMinDistance; // Return the maximum minimum distance
    }
};
