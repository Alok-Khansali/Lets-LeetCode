class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)    //Minimum Subarray of length n-k, n = size of the vector
    {
        int n = cardPoints.size(), sum = 0, minsum = 0;
        for (int i = 0, curr = 0; i < n; i++)
        {
            sum += cardPoints[i];
            curr += cardPoints[i];
            if (i < n - k)
                minsum += cardPoints[i];
            else
            {
                curr -= cardPoints[i - (n - k)];
                minsum = min(minsum, curr);
            }
        }
        return sum - minsum;
    }
};