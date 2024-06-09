// Approach 1 : BFS
class Solution
{
public:
    // Function to determine if there exists a valid path from start to end in the graph
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        vector<bool> visited(n, false); // Array to mark visited nodes
        vector<vector<int>> adjList(n); // Adjacency list to represent the graph

        // Constructing the adjacency list
        for (auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        // Performing BFS traversal to mark visited nodes
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Returning true if the end node is visited, indicating a valid path exists
        return visited[end];
    }
};
// Approach 2 : DFS
class Solution
{
public:
    // Function to determine if there exists a valid path from start to end in the graph
    bool validPath(int numNodes, vector<vector<int>> &edges, int startNode, int endNode)
    {
        vector<bool> visited(numNodes, false); // Array to mark visited nodes
        vector<vector<int>> adjList(numNodes); // Adjacency list to represent the graph

        // Constructing the adjacency list
        for (auto &edge : edges)
        {
            int nodeA = edge[0];
            int nodeB = edge[1];
            adjList[nodeA].push_back(nodeB);
            adjList[nodeB].push_back(nodeA);
        }

        stack<int> stack;
        stack.push(startNode);
        visited[startNode] = true;

        // Perform iterative DFS traversal
        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();

            // Explore neighbors of the current node
            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }

        // Check if the end node is visited, indicating a valid path exists
        return visited[endNode];
    }
};
// Fastest Approach : 99.84% faster
// Approach 3 : Union Find
class UnionFind
{
private:
    vector<int> parent;

public:
    // Constructor to initialize parent array
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i; // Initialize each node as its own parent
    }
    // Find operation with path compression
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    // Union operation with union by rank/heuristic
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            parent[rootX] = rootY; // Union by rank/heuristic
    }
};
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        UnionFind uf(n);

        // Union the edges
        for (auto &edge : edges)
        {
            uf.unite(edge[0], edge[1]);
        }
        // Check if start and end belong to the same set
        return uf.find(start) == uf.find(end);
    }
};