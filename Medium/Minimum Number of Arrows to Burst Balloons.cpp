class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)  //Memory Usage: 89.4 MB, less than 99.64% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        sort(points.begin(),points.end());
        int a = 1, l = points.size(),mn = points[0][1];
        for(int i = 1;i<l;i++)
        {
            mn = min(mn,points[i][1]);
            if(points[i][0] > mn)
            {
               a++;
               mn = points[i][1];
            }   
        }
        return a;
    }
};
