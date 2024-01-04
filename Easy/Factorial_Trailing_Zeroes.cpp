class Solution {
public:
    int trailingZeroes(int n) {
        int c=0;
        while(n)
            c+=n/5,n/=5;
        return(c);
    }
};
