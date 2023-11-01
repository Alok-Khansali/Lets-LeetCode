class Solution
{
public:
    vector<vector<int>> generate(int r)
    {
        vector<vector<int>> v(r);
        v[0].push_back(1);
        for (int i = 2; i <= r; i++)
        {
            v[i - 1].resize(i);
            v[i - 1][0] = v[i - 1][i - 1] = 1;
            for (int j = 1; j < i - 1; j++)
                v[i - 1][j] = v[i - 2][j] + v[i - 2][j - 1];
        }
        return (v);
    }
};