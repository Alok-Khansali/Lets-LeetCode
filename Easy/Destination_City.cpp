class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> outs;
        for (vector<string> v : paths)
            outs.insert(v[0]);
        for (vector<string> v : paths)
        {
            if (outs.find(v[0]) == outs.end())
                return v[0];
            if (outs.find(v[1]) == outs.end())
                return v[1];
        }
        return paths[0][0];
    }
};