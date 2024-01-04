class Solution  //99.79%faster
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int n = arr.size(), sum = 0, st = -1, en = -1;
        vector<int> prev(n + 1);
        for (int i = 1; i <= n; i++)
            prev[i] = arr[i - 1] + prev[i - 1];
        if (prev[n] % 3 != 0)
            return false;
        sum = prev[n] / 3;
        for (int i = 1; i <= n; i++)
        {
            if (prev[i] == sum)
            {
                st = i - 1;
                break;
            }
        }
        for (int i = n - 1; i > st; i--)
        {
            if (prev[n] - prev[i] == sum)
            {
                en = i;
                break;
            }
        }
        // cout << st << ' ' << en;
        return ((st != -1) && (en != -1) && (en - st > 1));
    }
};