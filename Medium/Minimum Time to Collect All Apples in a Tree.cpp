class Solution
{
public:
    int ans = 0;
    vector<vector<int>> mp;
    void dfs(int st, vector<bool> &a)
    {
        if (mp[st].empty())                // If the current vector is empty
            return;                        // No children to traverse, return
        vector<int> v = mp[st];            // Store the current set of child nodes
        for (int i = 0; i < v.size(); i++) // Traverse the current lot
        {
            dfs(v[i], a); // Check for the children nodes of the current nodes
            if (a[v[i]])  // If the current node has an apple
                          // Add 2 to the answer
                          // Set the parent node in the hasApple array to true,
                          // This creates a pathway back to the node 0,
                          // adding 2s along the way
                ans += 2, a[st] = true;
        }
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        // Create the tree
        mp.resize(n);
        unordered_set<int> st;
        for (vector<int> c : edges)
            if (st.find(c[1]) != st.end()) // if the current child node is a child of an existing node,
                                           // set it as a parent this time
                mp[c[1]].push_back(c[0]), st.insert(c[0]);
            else // Else setup the current child and parent node
                mp[c[0]].push_back(c[1]), st.insert(c[1]);
        // Do the DFS
        dfs(0, hasApple);
        return ans;
    }
};
// If leetcode chooses to get the bug accepted
class Solution
{
public:
    int ans = 0;
    vector<vector<int>> mp;
    void dfs(int st, vector<bool> &a)
    {
        if (mp[st].empty())
            return;
        vector<int> v = mp[st];
        for (int i = 0; i < v.size(); i++)
        {
            dfs(v[i], a);
            if (a[v[i]])
                ans += 2, a[st] = true;
        }
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        // Create the tree
        mp.resize(n);
        // sort(edges.begin(), edges.end());
        unordered_set<int> st;
        for (vector<int> c : edges)
            if (st.find(c[1]) != st.end())
                mp[c[1]].push_back(c[0]), st.insert(c[0]);
            else
                mp[c[0]].push_back(c[1]), st.insert(c[1]);
        // Do the DFS
        dfs(0, hasApple);
        return ans;
    }
};

// The way leetcode taught it, and the right way