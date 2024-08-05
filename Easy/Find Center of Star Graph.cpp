// Approach  : using frequency tab
// 86% faster
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        ios_base::sync_with_stdio(0);
        int numberOfEdges = edges.size();       // Number of edges
        int nodeDegreeCount[numberOfEdges + 2]; // Array to count occurrences (degrees) of each node
        // Initialize the array with zeros
        memset(nodeDegreeCount, 0, sizeof(nodeDegreeCount));
        // Iterate through each edge
        for (const vector<int> &edge : edges)
        {
            // Increment the degree count for each node in the edge
            nodeDegreeCount[edge[0]]++;
            nodeDegreeCount[edge[1]]++;
        }
        // Iterate through the node degrees
        for (int node = 1; node <= numberOfEdges + 1; node++)
        {
            // If a node appears in all edges, it is the center node
            if (nodeDegreeCount[node] == numberOfEdges)
                return node;
        }
        // Return 0 if no center node is found (although this case shouldn't happen in a valid star graph)
        return 0;
    }
};

// Approach 2 : Using the observation
// 82 ms 99.41% faster
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        ios_base::sync_with_stdio(0);
        // Extract nodes from the first two edges
        int firstNodeFirstEdge = edges[0][0];
        int secondNodeFirstEdge = edges[0][1];
        int firstNodeSecondEdge = edges[1][0];
        int secondNodeSecondEdge = edges[1][1];
        // Check if the center node is the first node of the first edge
        if (firstNodeFirstEdge == firstNodeSecondEdge || firstNodeFirstEdge == secondNodeSecondEdge)
            return firstNodeFirstEdge;
        // If not, the center node must be the second node of the first edge
        return secondNodeFirstEdge;
    }
};
