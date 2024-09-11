class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int start = colors[0], ans = 0, len = colors.size(), last = colors[len - 1];
        for (int i = len - 1; i >= 0; i--)
            if (colors[i] != start)
            {
                ans = i;
                break;
            }
        for (int i = 0; i < len; i++)
            if (colors[i] != last)
                return max(ans, len - i - 1);
        return 0;
    }
};