class Solution // No sort Approach
{
public:
    double average(vector<int> &salary)
    {
        double mn = INT_MAX, mx = INT_MIN, sum = 0, n = salary.size();
        if (n <= 2)
            return 0;
        for (double i : salary)
            mn = min(mn, i), mx = max(mx, i), sum += i;
        sum -= mn + mx;
        return (sum / (n - 2.0));
    }
};
// Sorting included
class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        double sum = 0, avg = 0.00000;
        for (int i = 1; i < salary.size() - 1; i++)
            sum += salary[i];
        avg = sum / (salary.size() - 2);
        return avg;
    }
};