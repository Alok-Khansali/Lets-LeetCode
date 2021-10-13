class Solution {                                          //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Triangle.
public:
    int minimumTotal(vector<vector<int>>& triangle)      
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        
        int n = triangle.size();
        for(int i=n-2; i >=0; i--)
        {
            for(int j=0;j<triangle[i].size(); j++)
            {
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);           // ADD the minimum of the two steps avaibale to the current position
            }
        }
        return triangle[0][0];                                                        //Bottom to top approach, therefore return the top most value
    }
};
