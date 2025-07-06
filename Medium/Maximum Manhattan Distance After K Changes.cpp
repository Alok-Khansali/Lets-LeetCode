class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int x = 0, y = 0, res = 0;
        for (char c : s)
        {
            if (c == 'N')
                y += k;
            else if (c == 'S')
                y -= k;
            else if (c == 'W')
                x -= k;
            else
                x += k;
            res = max(res, abs(x) + abs(y));
        }
        return res;
    }
};