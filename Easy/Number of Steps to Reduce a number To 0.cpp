class Solution {
public:
    int numberOfSteps(int n) {
        int c=0;
        while(n)
        {
            n = (n&1) ? n-1 : n/2;
            ++c;
        }
        return(c);
    }
};
