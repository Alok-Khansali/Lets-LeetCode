class Solution // Solvable in log(sum) * size of the array
{
public:
    bool chc(vector<int> &w, int d, int cap)
    {
        int x = 1, s = 0;
        for (int i = 0; i < w.size(); i++)
        {
            if (s + w[i] <= cap)
                s += w[i];
            else
                s = w[i], x++;
        }
        return (x <= d);
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        ios_base::sync_with_stdio(0);
        int s = 0, i = 0;
        for (int w : weights)
            s += w, i = max(i, w);
        while (i <= s)
        {
            int m = (i + s) / 2;
            if (chc(weights, days, m))
                s = m - 1;
            else
                i = m + 1;
        }
        return i;
    }
};