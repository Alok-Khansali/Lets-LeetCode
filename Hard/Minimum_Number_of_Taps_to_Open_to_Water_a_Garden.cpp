class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> Reach(n + 1);
        int count = 0, curr = 0, nxt = 0;
        for (int i = 0; i <= n; i++)
        {
            int st = max(0, i - ranges[i]), end = min(n, i + ranges[i]);
            Reach[st] = max(Reach[st], end);
        }
        for (int i = 0; i <= n; i++)
        {
            if (i > nxt)
                return -1;
            if (i > curr)
                count++, curr = nxt;
            nxt = max(Reach[i], nxt);
        }
        return count;
    }
};