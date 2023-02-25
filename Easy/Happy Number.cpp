class Solution
{
public:
    bool isHappy(int n)
    {
        int r, s = 100;
        while (s > 9)
        {
            s = 0;
            while (n > 0)
            {
                r = n % 10;
                s = s + r * r;
                n = n / 10;
            }
            n = s;
            if (s == 7)
                return (true);
        }
        return (s == 1);
    }
};