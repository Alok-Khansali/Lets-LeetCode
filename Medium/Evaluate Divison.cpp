class Solution 
{
    unordered_map<string, vector<pair<string, double>>> adja;
    unordered_map<string, bool> vis;
    double q_a;
public:
    bool dfs(string strt, string end, double prod)
    {
        if(strt == end and adja.find(strt)!=adja.end()) 
        {
            q_a = prod;
            return true;
        }
        bool tp = false;
        vis[strt] = true;
        for(int i = 0; i < adja[strt].size(); i++)
            if(!vis[adja[strt][i].first])
            {
                tp = dfs(adja[strt][i].first, end, prod*adja[strt][i].second);
                if(tp)
                    break;
            }
        vis[strt] = false;
        return tp;   
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        for(int i = 0; i < n ; i++)
        {
            adja[equations[i][0]].push_back({equations[i][1], values[i]});
            adja[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            vis[equations[i][0]] = vis[equations[i][1]] = false;
        }
        for(int i = 0; i < m ; i++)
        {
            bool pf = dfs(queries[i][0], queries[i][1], 1);            
            q_a = 1, ans[i] = (pf) ? q_a : -1; 
        }
        return ans; 
    }
};