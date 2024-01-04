// Better than 96.40% submissions
class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        double i = 1, j = 1e7 + 5;
        int ans = j;
        while (i <= j)
        {
            double m = floor((i + j) / 2.0), time = 0;
            for (double n : dist)
                time = ceil(time), time += n / m;
            if (time <= hour)
                ans = min(ans, (int)m), j = m - 1;
            else
                i = m + 1;
        }
        return ((ans == 1e7 + 5) ? -1 : ans);
    }
};