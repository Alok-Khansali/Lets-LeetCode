class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        long s=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<c;i++)
           s += grid[0][i] + grid[r-1][i];
        for(int i=0;i<r;i++)
           s += grid[i][0] + grid[i][c-1];
        for(int i=0;i<r;i++)
            for(int j=1;j<c;j++)
                s += abs(grid[i][j]-grid[i][j-1]);
        for(int i=0;i<c;i++)
            for(int j=1;j<r;j++)
                s += abs(grid[j][i]-grid[j-1][i]);
        return(s); 
    }
};
