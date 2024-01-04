class Solution {
public:
    int climbStairs(int n) 
    {
        int c=0;
        for(int i=1,a=0,b=1;i<=n;i++,c=a+b,a=b,b=c);
        return(c);
    }
};
