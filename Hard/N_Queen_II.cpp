class Solution
{
public:
    int ans = 0;
    bool Check(int r, int c, vector<string> &v, int n)
    {
        // Check =ing if the Queen Can be Placed in the Column
        for (int i = 0; i <= r; i++)
            if (v[i][c] == 'Q')
                return false;
        int x = r, y = c;
        // It is for Sure than the Queen can't be present along the horizontal, so it is Skipped
        while (x >= 0 && y >= 0) // Checking if the Queen can be met at the main Diagonal
        {
            if (v[x][y] == 'Q')
                return false;
            x--, y--;
        }
        x = r, y = c;
        while (x >= 0 && y < n) // Checking if the Queen can be met at the Secondary Diagonal
        {
            if (v[x][y] == 'Q')
                return false;
            x--, y++;
        }
        return true;
    }
    void Backtrack(int r, vector<string> &v, int n)
    {
        if (r == n)
        {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++)
            if (Check(r, i, v, n)) // Check if queen can be placed on a square, if yes, check for variations
            {
                v[r][i] = 'Q';
                Backtrack(r + 1, v, n);
                v[r][i] = '.';
            }
    }
    void NQueensII(int n)
    {
        ans = 0;
        vector<string> v;
        string s(n, '.');
        for (int i = 0; i < n; i++)
            v.push_back(s);
        Backtrack(0, v, n);
    }
    int totalNQueens(int n)
    {
        NQueensII(n);
        return ans;
    }
};

/* //never use this, i repeat NEVER!!!!!
class Solution
{
public:
    int totalNQueens(int n)
    {
        int a[10] = {0,1,0,0,2,10,4,40,92,352};
        return a[n];
    }
};
*/