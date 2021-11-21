class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        priority_queue<pair<int,int>> pq;
        int l = costs.size(), cost=0;
        for(int i=0;i<l;i++)
        {
            pq.push({costs[i][1]-costs[i][0],i});
        }   
        for(int i=0;i<l/2;i++)                     //First half goes to A
        {
            cost += costs[pq.top().second][0];
            pq.pop();
        }
        for(int i=0;i<l/2;i++)                    //Second goes to B
        {
            cost += costs[pq.top().second][1];
            pq.pop();
        }
      return cost;
    }
};
