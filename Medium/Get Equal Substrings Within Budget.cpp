class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int st = 0, length = 0, sz = s.size(), i = 0;
        int a[sz];
        memset(a, 0, sizeof(a));
        while (i < sz && st < sz)
        {
            if (a[i] == 0)
                a[i] = abs(s[i] - t[i]), maxCost -= a[i];
            // cout << a[i] << " " << i << " " << maxCost << " " << st <<'\n';
            if (maxCost >= 0)
                i++;
            else
                maxCost += a[st++];
            length = max(length, i - st);
        }
        return length;
    }
};