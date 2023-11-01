// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Champagne Tower.
// Memory Usage: 6.4 MB, less than 73.98% of C++ online submissions for Champagne Tower.
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        // Setting up the glasses
        double glass[102][101];
        // Placing them Empty
        memset(glass, 0, sizeof(glass));
        // And finally pouring the glass
        glass[0][0] = poured;
        // Simulate the pouring till the Query_Row
        for (int i = 0; i <= query_row; i++)
            // Each Row has Row_Number + 1 Glasses
            for (int j = 0; j <= i; j++)
                // If a Glass is overflows
                if (glass[i][j] > 1.0)
                {
                    // Get the overflow quantity
                    double rem = glass[i][j] - 1;
                    // And divide it equally between the two glasses below
                    glass[i][j] = 1, glass[i + 1][j] += rem / 2, glass[i + 1][j + 1] += rem / 2;
                }
        /*
        // To check what glass hold what quantity
    for(int i = 0; i < 101;i++){  for(int j = 0; j <= i;j++) cout << glass[i][j] << ' '; cout << '\n'; }
        */
        return glass[query_row][query_glass];
    }
};

// First Draft, when all i knew was hard work
class Solution
{ // Runtime: 25 ms, faster than 32.66% of C++ online submissions for Champagne Tower.
  // Memory Usage: 14.4 MB, less than 41.52% of C++ online submissions for Champagne Tower.
public:
    vector<double> dp(vector<double> curr, int qr, int s)
    {
        if (s == qr + 1)
            return curr;
        vector<double> temp(s + 1, 0);
        for (int i = 0; i < s; i++)
        {
            double x = curr[i] - 1;
            if (x > 0)
                temp[i] += x / 2.0, temp[i + 1] += x / 2.0;
        }
        return (dp(temp, qr, s + 1));
    }
    double champagneTower(int poured, int query_row, int query_glass)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<double> ans = dp({(double)poured}, query_row, 1);
        return (ans[query_glass] > 1 ? 1.00000 : ans[query_glass]);
    }
};