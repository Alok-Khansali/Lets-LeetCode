class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        // Continuously add the max of differences between the coordinates, next tym dont use extra speed
        // Runtime: 13 ms, faster than 60.41% of C++ online submissions for Minimum Time Visiting All Points.
        // Memory Usage: 10.1 MB, less than 67.72% of C++ online submissions for Minimum Time Visiting All Points.
        ios_base::sync_with_stdio(0);
        int ans = 0, len = points.size();
        for (int i = 1; i < len; i++)
            ans += (max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1])));
        return ans;
    }
};