class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<long long> pq1, pq2;
        long long t = 0, sum = 0, len = costs.size(), i = 0, j = len - 1;
        pq1.push(INT_MIN);
        pq2.push(INT_MIN);
        while (i < j && i < candidates)
        {
            pq1.push(-costs[i]);
            ++i;
        }
        while (j >= i && len - j <= candidates)
        {
            pq2.push(-costs[j]);
            --j;
        }
        // cout << len << ' ' << j << '\n';
        while (k--)
        {
            // cout << pq1.top() << ' ' << pq2.top() << '\n';
            if (pq1.top() > pq2.top())
            {
                sum -= pq1.top();
                // cout << sum << '\n';
                pq1.pop();
                if (i <= j)
                    pq1.push(-costs[i++]);
            }
            else if (pq1.top() < pq2.top())
            {
                sum -= pq2.top();
                // cout << sum << '\n';
                pq2.pop();
                if (i <= j)
                    pq2.push(-costs[j--]);
            }
            else
            {
                if (costs[i] <= costs[j])
                {
                    sum -= pq1.top();
                    pq1.pop();
                    if (i <= j)
                        pq1.push(-costs[i++]);
                }
                else
                {
                    sum -= pq2.top();
                    pq2.pop();
                    if (i <= j)
                        pq2.push(-costs[j--]);
                }
            }
        }
        return sum;
    }
};