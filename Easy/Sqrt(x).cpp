class Solution {
public:
    int mySqrt(double n) 
    {
       if(n==0)
           return(0);
        double t = 0,s = n/2;
        while((t-s)!=0)
            t = s, s = (t+ (n/t)) /2;
        return((int)s);   
    }
};
/* binary search approach
class Solution {
public:
    int mySqrt(int n) {
        if(n<2)
            return n;
        int l=1,h=n/2;
        while(l<=h)
        {
            int mid = l+(h-l)/2;       //overflow prevention
            if(mid == n/mid)
                return mid;
            else if(mid<n/mid)
                l=mid+1;
            else
                h=mid-1;
        }
        return h;
    }
};
*/
