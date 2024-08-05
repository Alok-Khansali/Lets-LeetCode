class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        // assign as per the roads available from
        // heap game
        ios_base::sync_with_stdio(0);
        int a[n], finRd[n];
        long long res = 0;
        memset(a, 0, sizeof(a));
        memset(finRd, 0, sizeof(finRd));
        priority_queue<pair<int, int>> pq;
        for (vector<int> v : roads)
        {
            a[v[0]]++;
            a[v[1]]++;
        }
        for (int i = 0; i < n; i++)
            pq.push({a[i], i});
        while (!pq.empty())
        {
            finRd[pq.top().second] = n--;
            pq.pop();
        }
        for (vector<int> v : roads)
        {
            res += finRd[v[0]] + finRd[v[1]];
        }
        return res;
    }
};