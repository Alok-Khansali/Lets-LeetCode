class Solution {
public:
    static const int N = 100001;
    vector<int> v[N];
    bool checked[N];
    void dfs(string& s, int vertex, vector<char>& cr, vector<int>& ind) 
    {
        //Adding the character and index 
        cr.push_back(s[vertex]);
        ind.push_back(vertex);
        checked[vertex] = true;
        for (int itr : v[vertex]) 
            if (!checked[itr]) 
                dfs(s, itr, cr, ind);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        for (vector<int> edge : pairs) 
        {
            int src = edge[0], dst = edge[1];
            v[src].push_back(dst);
            v[dst].push_back(src);
        }
        for (int vertex = 0; vertex < s.size(); vertex++) 
            if (!checked[vertex]) 
            {
                vector<char> cr;
                vector<int> ind;
                
                dfs(s, vertex, cr, ind);
                sort(cr.begin(), cr.end());    // Sort
                sort(ind.begin(), ind.end());

                for (int index = 0; index < cr.size(); index++) 
                    s[ind[index]] = cr[index];
            }
        return s;
    }
};