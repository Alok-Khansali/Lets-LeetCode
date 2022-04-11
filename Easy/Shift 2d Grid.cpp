class Solution {  //Runtime: 27 ms, faster than 80.91% of C++ online submissions for Shift 2D Grid.
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        if(k == 0)
            return grid;
        int n = grid.size(), m = grid[0].size();
        k %= (n*m);
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j >= 0;j--)
            {
                ans [(i + (j +k)/m)% n][(j + k)% m] = grid[i][j];
            }
        }
        return ans;
    }
};