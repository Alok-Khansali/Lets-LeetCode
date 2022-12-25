class Solution 
{
public:
    bool digitCount(string num) 
    {
        int a[10] = {0};
        for(int i = 0; i < num.size(); i++)
            a[num[i] - '0']++;
        for(int i = 0; i < num.size(); i++)
            if( a[i] != num[i] - '0' )
            return false;
        return true;
    }
};