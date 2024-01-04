class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int x = piles.size() / 3, ans = 0;
        for (int i = x * 3 - 2; x > 0; x--, i -= 2)
            ans += piles[i];
        return ans;
    }
};