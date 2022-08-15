class Solution {   //Runtime: 19 ms, faster than 96.72% of C++ online submissions for Is Graph Bipartite?.
public:
    vector<int>vt,cl;
    bool dfs(int v, int c, vector<vector<int>>& g)
    {
        vt[v]=1;
        cl[v]=c;
        for(int cld : g[v])
            if(vt[cld]==0)
            {
                if(dfs(cld,c^1,g)==false) 
                    return false;
            }
            else
            {
                if(cl[v] == cl[cld])
                    return false;
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vt.resize(n);
        cl.resize(n);
        for(int i = 0;i<n;++i)
            if(vt[i] == 0 && dfs(i,0,graph) == false)
                return false;        
        return true;
    }
};