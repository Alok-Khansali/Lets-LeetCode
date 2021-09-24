class Solution {
public:
    int tribonacci(int n) 
    {
        if(n==0)
            return n;
        if(n<3)
            return 1;
        int x=0;
        for (int i=0,a=0,b=1,c=1;i<=n-3;i++,x=a+b+c,a=b,b=c,c=x);
        return x;
    }
};
