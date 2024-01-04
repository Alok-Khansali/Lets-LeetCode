class Solution
{
public:
    void dpdp(vector<vector<double>> &v, int i, )
    {

    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        double a[nums.size() + 1] = {0};
        int x = nums.size();
        double dp[x + 1][k]; // x +1 states , k transitions
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; i < x; j++)
        }
    }
};