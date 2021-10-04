class Solution {
public:
    bool isUgly(int n) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        if(n<1)
            return false;
      
        while(n%2 == 0)
            n/=2;
      
        while(n%3 == 0)
            n/=3;
      
        while(n%5 == 0)
            n/=5;
      
        return n == 1;
    }
};
