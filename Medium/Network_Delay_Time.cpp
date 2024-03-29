class Solution // Redo
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> dis(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> adj[n + 1];
        for (int j = 0; j < times.size(); j++) // Graph creation
        {
            int u = times[j][0], v = times[j][1], w = times[j][2];
            adj[u].push_back({v, w});
        }
        dis[k] = 0; // Time from K to K is 0
        pq.push({0, k});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto vec : adj[u]) // vec is vector containing v and w
            {
                int v = vec[0], w = vec[1];
                if (dis[u] + w < dis[v])
                {
                    pq.push({dis[u] + w, v});
                    dis[v] = w + dis[u];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == INT_MAX)
                return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};