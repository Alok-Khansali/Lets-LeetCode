class Solution
{
public:
    int pivotInteger(int n)
    {
        int pref[n + 1], suff[n + 2];
        memset(pref, 0, sizeof(pref));
        memset(suff, 0, sizeof(suff));
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + i;
        for (int i = n; i > 0; i--)
            suff[i] = suff[i + 1] + i;
        for (int i = 1; i <= n; i++)
            if (pref[i] == suff[i])
                return i;
        return -1;
    }
};