class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long kids)
    {
        long long maxCandiesPerChild = 0;
        int left = 1, right = 1e7;
        while (left <= right)
        {
            long long mid = (left + right) / 2, totalPieces = 0;
            for (int candyCount : candies)
                totalPieces += (candyCount / mid);
            if (totalPieces >= kids)
            {
                maxCandiesPerChild = max(maxCandiesPerChild, mid);
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return maxCandiesPerChild;
    }
};