// 100% faster
// 93.51% better space utilisation
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xr = start ^ goal;
        return __builtin_popcount(xr);
    }
};