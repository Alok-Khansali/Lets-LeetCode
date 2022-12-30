class Solution // Approach 1, 64.19% better than the other approaches available
{
public:
    vector<vector<int>> ans;
    void some_function(vector<int> v, int x, vector<vector<int>> &g)
    {
        if (g[x].empty())                 // States the end point in the graph
            return;
        for (int i : g[x])                // Search the adjoining vertices
        {
            v.push_back(i);               // Push the vertex
            if (i == g.size() - 1)        // if it is n-1, insert in the set
                ans.push_back(v);
            else 
                some_function(v, i, g);   // Else check the adjoining vertices of the current vertex
            v.pop_back();                 // pop the current vertex
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        ios_base::sync_with_stdio(0);
        some_function({0}, 0, graph);
        return ans;
    }
};