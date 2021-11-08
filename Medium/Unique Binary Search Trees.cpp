class Solution {     
public:
    int numTrees(int n)            //Can be calculated using Nth- catalan Number algorithm     ((2*n) C n)/n+1
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        unsigned long long int f = 1,r=1;
        for(int i = n+1; i <= 2*n; i++,r++)
        {
            f = (f * i)/r; 
        }
        return f/(n+1);
    }
};