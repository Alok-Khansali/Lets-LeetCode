//No Priority Queue Solution
class Solution {   //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Two City Scheduling.
                  //Memory Usage: 7.9 MB, less than 47.20% of C++ online submissions for Two City Scheduling.
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return(abs(a[0] - a[1]) > abs(b[0] - b[1]));     //Lesser the diff more the priority
    }
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
       int o = 0,t = 0, l = costs.size(),ans = 0;
       sort(costs.begin(),costs.end(),cmp);            //Comaprator sort based on the difference of the two values
       for(auto i : costs)
       {
           if(i[0] <= i[1])
               if(o < l/2)
               {
                   ans += i[0];
                   o++;
               }
               else
               {
                   ans += i[1];
                   t++;
               }
           else
               if(t < l/2)
               {
                   ans += i[1];
                   t++;
               }
               else
               {
                   ans += i[0];
                   o++;
               }
       }
       return ans;
    }
};
/*
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
*/
