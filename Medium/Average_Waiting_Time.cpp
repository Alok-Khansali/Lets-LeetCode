class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double ans = 0, curr = 0, len = customers.size();
        for (vector<int> v : customers)
        {
            curr = max((double)v[0], curr) + v[1];
            ans += (curr - v[0]);
        }
        return ans / len;
    }
};