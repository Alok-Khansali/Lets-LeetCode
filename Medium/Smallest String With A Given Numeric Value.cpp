class Solution  //Runtime: 36 ms, faster than 89.39% of C++ online submissions for Smallest String With A Given Numeric Value.
                //Memory Usage: 21.1 MB, less than 90.88% of C++ online submissions for Smallest String With A Given Numeric Value.
{
public:
    string getSmallestString(int n, int k) 
    {
        string s(n,'a');
        k -= n;                                               // No of a_s have been subtracted
        while(k)                                              //Building the String from the end
        {
            if(k >= 25)                                       //Insert z if k >= 25, as no other char with 
            {
                s[--n] = 'z';                                 //Set the char at pos n as z
                k -= 25;                                      // subtract 25 
            }
            else
            {
                s[--n] += k;                                 // Advance the char at r(th) position by k
                return s;
            }
        }
        return s;
    }
};
/*
class Solution   //Runtime: 40 ms, faster than 82.26% of C++ online submissions for Smallest String With A Given Numeric Value.
                 //Memory Usage: 21.2 MB, less than 63.44% of C++ online submissions for Smallest String With A Given Numeric Value.
{
public:
    string getSmallestString(int n, int k) 
    {
        string s(n,'a');                                        // Auxilliary String of size n
        int r = 0;
        while(n--)                                              // Building the String from the start
        {
            int x = max(k - 26 * n,1);                          // Find the optimum value
            s[r++] += x-1;                                      // Advance the char at r(th) position by max(0,x-1)
            k -= x;                                             // Reduce k
        }
        return s;
    }
};
*/