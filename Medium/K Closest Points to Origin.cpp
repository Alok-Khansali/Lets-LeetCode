class Solution {    //Runtime: 120 ms, faster than 99.28% of C++ online submissions for K Closest Points to Origin.
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
      
        vector<pair<double,pair<int,int>>> ar;
        vector<vector<int>> answer;
      
        for(int i=0;i<points.size();i++)
        {
            double x = points[i][0], y = points[i][1], c = sqrt(x*x + y*y);
            ar.push_back({c,{x,y}});
        }
      
        sort(ar.begin(),ar.end());
      
        for(int i=0;i<k;i++)
        {
            answer.push_back({ar[i].second.first,ar[i].second.second});
        }
      
        return answer;
    }
};
