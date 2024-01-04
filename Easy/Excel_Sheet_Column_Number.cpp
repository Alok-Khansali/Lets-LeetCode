class Solution {
public:
    int titleToNumber(string ct) 
    {
        long long int a=0,i=ct.size()-1;
        for(int j = 0;j <= i ;j++)
            a += (pow(26,i-j) * (ct[j]-'A' + 1));
        return a;
    }
};