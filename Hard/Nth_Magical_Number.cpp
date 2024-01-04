class Solution 
{
  public:
    int nthMagicalNumber(int n, int a, int b) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        long l = min(a,b), r = n*l, x = lcm(a,b), m, fct, res;
        while(l<=r)
        {
            m = l + (r-l)/2, fct = m/a + m/b - m/x;
          
            if(fct < n)
                l = m+1;
            else
            {
                r = m-1;
                res = m;
            }
        }
        return res % 1000000007;
    }
};
