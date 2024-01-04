class Solution // Runtime: 1190 ms, faster than 18.44% of C++ online submissions for Critical Connections in a Network.
{
public:
    vector<int> des{0}, lw{0};
    int time = 1;
    vector<vector<int>> res;
    unordered_map<int, vector<int>> mp_edge;

    void dfs(int curr, int prev)
    {
        des[curr] = lw[curr] = time++;
        for (int next : mp_edge[curr])
        {
            if (des[next] == 0)
            {
                dfs(next, curr);
                lw[curr] = min(lw[curr], lw[next]);
            }
            else if (next != prev)
                lw[curr] = min(lw[curr], des[next]);
            if (lw[next] > des[curr])
                res.push_back({curr, next});
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        ios_base::sync_with_stdio(0);
        des = vector<int>(n);
        lw = vector<int>(n);
        for (auto conn : connections)
        {
            mp_edge[conn[0]].push_back(conn[1]);
            mp_edge[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return res;
    }
};