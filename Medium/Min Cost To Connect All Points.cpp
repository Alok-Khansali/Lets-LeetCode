class Solution { //Runtime: 364 ms, faster than 67.01% of C++ online submissions for Min Cost to Connect All Points.
    //Memory Usage: 58 MB, less than 70.73% of C++ online submissions for Min Cost to Connect All Points.
public:
    int parent[1001];    
    int find(int a)                                                              // find function to find parent of a node
    {
        if(parent[a] < 0)
            return a;
        
        return parent[a] = find(parent[a]);                                      // path compression
    }
    void Union(int a, int b)
    {
        parent[a] = b;                                                           //now parent of a is b
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size(), sum = 0; 
        memset(parent,-1,sizeof(parent));
        vector<pair<int, pair<int, int>>> adj;
        for(int i = 0; i < n; i++)                                               // Graph with manhattan distance as weights
            for(int j = i + 1; j < n; j++)
            {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);  //manhattan distance
                adj.push_back({weight, {i, j}});
            }
        sort(adj.begin(), adj.end());                                            // sort as per edge weight
        for(int i = 0; i < adj.size(); i++)
        {
            int a = find(adj[i].second.first), b = find(adj[i].second.second);   // 1st and 2nd node
            if(a != b) 
            {
                sum += adj[i].first;
                Union(a, b);                                                     // now merge them
            }
        }
        return sum;                                                              // return the min value
    }
};