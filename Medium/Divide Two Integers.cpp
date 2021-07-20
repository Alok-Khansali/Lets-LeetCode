class Solution {
public:
    int divide(long long int dd, long long int d) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long int s=1,t=0,a=0;
        if (dd==0)
            return 0;
        if((dd<0) ^ (d<0))
            s=-1;
        dd=abs(dd),d=abs(d);
        for (long long int i = 31; i >= 0; --i)
             if (t + (d << i) <= dd)
                  t += d << i,  a |= 1LL << i;
        return( (s==1) ?(a>INT_MAX ? INT_MAX : a) : s*a);
    }
};
