class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size(), candy = n, i = 1, peak = 0, valley = 0;
        ;
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                i++;
                continue;
            }
            while (ratings[i] > ratings[i - 1])
            {
                peak++, candy += peak, i++;
                if (i == n)
                    return candy;
            }
            while (i < n && ratings[i] < ratings[i - 1])
                valley++, candy += valley, i++;
            candy -= min(peak, valley); // Keep only the higher peak
        }
        return candy;
    }
};