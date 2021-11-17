class Solution {                      //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths
                                      //Memory Usage: 5.9 MB, less than 70.03% of C++ online submissions for Unique Paths.
public:
    int uniquePaths(int m, int n) 
    {
	    //It can be easily deduced that, to reach the destination (m-1) moves are to be taken downwards and (n-1) moves to the right
        //The idea here is to choose either the (m-1) step down or (n-1) steps right out of (m+n-2) steps.
        //The one that is not choosen, say, the moves to the right, will just act as fillers in the path
        
        long result = 1,mx = max(n,m);                 //Take long datatype for result and since its confirmed that answer will be <= 2 * 10^9,it will easily be returned
        for(int i = mx,r = 1; i <= n + m - 2; i++,r++) //We know that max(m-1,n-1)! will be cancelled for sure from (m+n-2)! 
        {                                              //Therefore start from max(m,n) and start the smaller 
            result = (result * i)/r;                   //(n + m -2) - (m - 1) = (n - 1), therefore 'r' will reach the max value of (n-1) and that is only required
        }
        return result;                                 //Return the value for which the code was return
    }
};
