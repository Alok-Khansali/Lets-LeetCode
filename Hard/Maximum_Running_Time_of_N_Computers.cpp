class Solution
{
public:
    bool possible(int n, vector<int> &batteries, long long int hrs)
    {
        long long int sum = 0;
        for (int i = 0; i < batteries.size(); i++)
        {
            sum += batteries[i];
            if (sum >= hrs)
                sum -= hrs, n--;
            if (n == 0)
                return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long int start = 1, end = 0;
        for (int i = 0; i < batteries.size(); i++)
            end += batteries[i];
        end /= n;
        sort(batteries.begin(), batteries.end());
        while (start < end)
        {
            long long int mid = start + (end - start + 1) / 2;
            if (possible(n, batteries, mid))
                start = mid;
            else
                end = mid - 1;
        }
        return start;
    }
};