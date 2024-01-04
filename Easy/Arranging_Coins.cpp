class Solution {   //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arranging Coins.
public:
    //The given question is uses the sum of first N numbers.
    //We need to find the maximum value (x), which satisfies the equation x*(x+1)/2 <= N
    int arrangeCoins(int n)                 
    {
        ios_base::sync_with_stdio(false);   //Speed
	    cin.tie(NULL); 
        long i =1,j = n,answer=0;           // i = Lower_bound, j = Upper_bound, Answer is what is stated as x in the above equation
        while(i <= j)                       // Binary search to get he solution in O(log(n)) time
        {
            long m = i + (j-i)/2;            // m = mid of upper and lower bound, this also helps to prevent the overflow while calculating the mid value 
            if( (m*(m+1))/2 <= n)           //Whenever the equation is satisfied we store the mid in answer variable
            {
                answer = m;
                i = m + 1;                  //And raise the lower_bound to (mid + 1)
            }
            else
            {
                j = m - 1;                  //Else we reduce the upper_bound to (mid - 1)
            }
        }
        return answer;                      //Finally we have our Answer
    }
};
/*Alternatively there exists an O(1) Solution too
class Solution {   Runtime: 4 ms, faster than 68.61% of C++ online submissions for Arranging Coins.
public:
    int arrangeCoins(double n)                 
    {
        int answer = floor(-0.5 + sqrt(2*n + 0.25));
        return answer;                      
    }
};
*/