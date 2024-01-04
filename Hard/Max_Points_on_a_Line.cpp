// Approach 1
class Solution   // 95.7% faster, 53.96% space efficient
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 1, temp = 1, l = points.size();
        for (int i = 0; i < l; i++, temp = 1)
        {
            unordered_map<double, int> slp;
            for (int j = i + 1; j < l; j++)
            {
                double x = (double)(points[i][0] - points[j][0]), y = (double)(points[i][1] - points[j][1]);
                if (x == 0)
                    slp[1e6]++;
                else
                    slp[y / x]++;
            }
            for (auto i : slp)
                temp = max(temp, i.second + 1);
            ans = max(ans, temp);
        }
        return ans;
    }
};
// leetcode solution
class Solution
{
public:
    int maxPoints(vector<vector<int>> &pt)
    {
        int ans = 1, n = pt.size();
        for (int i = 0; i < n - 1; i++)
        {
            map<double, int> mp;
            for (int j = i + 1; j < n; j++)
            {
                double x = (double)(pt[j][1] - pt[i][1]) / (double)(pt[j][0] - pt[i][0]); // slope
                if (pt[j][1] - pt[i][1] < 0 && (pt[j][0] - pt[i][0]) == 0)                // infinite slop for Perpendicular line
                    mp[abs(x)]++;
                else
                    mp[x]++;
            }
            int temp = 0;
            for (auto it : mp)
                temp = max(temp, it.second + 1);
            ans = max(temp, ans);
        }
        return ans;
    }
};