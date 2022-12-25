class Solution // Brute force
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        int a[m][n], ans = 0;
        memset(a, 0, sizeof(a));
        for (vector<int> v : indices)
        {
            for (int i = 0; i < n; i++)
                a[v[0]][i]++;
            for (int i = 0; i < m; i++)
                a[i][v[1]]++;
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += (a[i][j] & 1);
        return ans;
    }
};

// Better complexity
class Solution
{
public:
    int row[50] = {false}, col[50] = {false};
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        for (int i = 0; i < indices.size(); i++)
        {
            row[indices[i][0]] ^= true;
            col[indices[i][1]] ^= true;
        }
        int cntrow = 0, cntcol = 0;
        for (int i = 0; i < 50; i++)
        {
            if (row[i] == true)
                cntrow++;
            if (col[i] == true)
                cntcol++;
        }
        return n * cntrow + m * cntcol - (2 * cntrow * cntcol);
    }
};