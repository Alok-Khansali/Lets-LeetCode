// This falis at only 1 test
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int x = left & right;
        for (long long i = (long long)left + 1; i < right; i++)
        {
            x &= i;
            if (x == 0)
                return 0;
        }
        return x;
    }
};
// This one passes that too
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int c = 0;
        while (left != right)
        {
            left >>= 1, right >>= 1, c++;
        }

        return left << c;
    }
};