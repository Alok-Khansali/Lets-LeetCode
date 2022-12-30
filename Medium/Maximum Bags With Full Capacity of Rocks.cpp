class Solution  // 100% faster
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = rocks.size(), a[n], ans = 0;
        for (int i = 0; i < n; i++)
            a[i] = capacity[i] - rocks[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                ans++;
            else if (additionalRocks >= a[i])
            {
                additionalRocks -= a[i];
                ans++;
            }
            else
                break;
        return ans;
    }
};