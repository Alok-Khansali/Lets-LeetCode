class Solution {
public:
    vector<int> distributeCandies(long candies, long n) 
    {
       ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
       vector<int> v(n,0);
        long c=0,r=1;
       while(candies>0)
       {
          for(long i=0;i<n;i++)
          {
              c = min(r, candies);
              v[i] += c;
              candies -= c;
              r++;
              if(candies == 0)
              {
                  break;
              }
          }
       }
        return v;
    }
};
