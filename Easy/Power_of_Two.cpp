class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        ios_base::sync_with_stdio(false);
        if( n <= 0)
            return false;                   
                                            //        binary        binary             
       return ( (n&(n-1)) == 0);            //Eg: 4 -> 1000 and 3 -> 111     ::  4&3 = 0
    }
};
/*
//Alternately We can solve it using log2()  but it is slower as compared to the above mentioned approach
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if( n <= 0)
            return false;
       return (log2(n) == (int)log2(n)); 
    }
};
*/
