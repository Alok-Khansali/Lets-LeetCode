class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        ios_base::sync_with_stdio(0);
        // Create adjacency list and in-degree count
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        // Perform topological sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        // Initialize ancestor lists
        vector<set<int>> dp(n);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node])
            {
                // Add current node's ancestors to the neighbor's ancestor list
                dp[neighbor].insert(node);
                dp[neighbor].insert(dp[node].begin(), dp[node].end());
                // Decrement in-degree and add to queue if it becomes 0
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        // Convert sets to vectors for the final result
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i)
            result[i] = vector<int>(dp[i].begin(), dp[i].end());

        return result;
    }
};