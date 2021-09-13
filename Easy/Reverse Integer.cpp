class Solution {
public:
    int reverse(int x) 
    {
        long long y=1,rev=0;
        if(x<0)
            y=-1, x*=y;
        while(x>0)
        {
            rev=rev*10+x%10;
            if(rev>INT_MAX)
                return(0);
            x/=10;
        }
        return(rev*y);
    }
};
