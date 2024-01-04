class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) 
    {
        if(a.size()<3)
            return false;
        for(int i=0;i<=a.size()-3;i++)
            if( a[i]%2 == 1 && a[i+1]%2 == 1 && a[i+2]%2 == 1 )
                return true;
        return false;
    }
};
