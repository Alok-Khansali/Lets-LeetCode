class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        cout.tie(NULL);
        if(n == 0)
            return false;
       double b = log2(n)/2;
       return(b == round(b));
    }
};
