class Solution {
public:
    // Function to find the minimum number of rectangles needed to cover the points
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) 
    {
        // Sort the points based on their x-coordinates
        sort(points.begin(), points.end());
        int count = 0; // Initialize the count of rectangles
        int len = points.size(); // Get the number of points
        // Iterate through the sorted points
        for(int i = 0; i < len;)
        {
            int x = points[i][0]; // Get the current x-coordinate
            // Check the width of the current rectangle
            while(++i < len && points[i][0] <= x + w);
            count++; // Increment the count of rectangles
        }
        return count; // Return the minimum number of rectangles
    }
};
