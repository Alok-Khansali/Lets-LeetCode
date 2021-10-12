/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int i = 1, j = n;                   //i = lower bound and j = upper bound for the binary search algorithm
        while(i <= j)
        {
            int m =  i + (j - i)/2;         // To prevent overflow, It's a Good Practice to write (i+u)/2 as  i + (u - i)/2
            
            int a = guess(m);               //Asking the api for input
            if(a == 1)                      //pick > num
            {
                i = m + 1;
            }
            else if(a == -1)                //pick < num
            {
                j = m - 1;
            }
            else                            // pick == num
            {
                return m;
            }   
        }
        return 0;
    }
};
