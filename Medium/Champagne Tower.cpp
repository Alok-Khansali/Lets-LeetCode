class Solution {  //Runtime: 2 ms, faster than 96.96% of C++ online submissions for Champagne Tower.
                  //Memory Usage: 6.1 MB, less than 75.19% of C++ online submissions for Champagne Tower.
public:           //My second draft is genrally better than my first one
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        double arr[100][100] = {0},z=0;
        arr[0][0] = poured;
        for(int i = 0;i<query_row;i++)
            for(int j = 0;j<=i;j++)
            {
                double x = arr[i][j] - 1.0;
                if(x >= 0)
                {
                    arr[i+1][j] += x/2.0;
                    arr[i+1][j+1] += x/2.0;
                }
            }
        z = arr[query_row][query_glass];
        return (z > 1 ? 1 : z);
    }
};
/* //First Draft
class Solution {  //Runtime: 25 ms, faster than 32.66% of C++ online submissions for Champagne Tower.
                   //Memory Usage: 14.4 MB, less than 41.52% of C++ online submissions for Champagne Tower.
public:
    vector<double> dp(vector<double> curr,int qr,int s)
    {
        if(s == qr + 1)
            return curr;
        vector<double> temp(s+1,0);
        for(int i = 0;i<s;i++)
        {
            double x = curr[i] - 1;
            if(x > 0)
                temp[i] += x/2.0, temp[i+1] += x/2.0;
        }
        return(dp(temp,qr,s+1));
    }
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        vector<double> ans = dp({(double)poured},query_row,1);
        return (ans[query_glass] > 1 ? 1.00000 : ans[query_glass]);
    }
};
*/