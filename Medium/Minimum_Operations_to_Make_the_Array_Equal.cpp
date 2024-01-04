class Solution {
public:
    int minOperations(int n) {
        int s=0;
        n-=1;
        while(n>0)
            s+=n,n-=2;
        return s;
    }
};
