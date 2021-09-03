class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) 
    {
        vector<bool> v(c.size());
        int m=*max_element(c.begin(),c.end());
        for(int i=0;i<c.size();i++)
            v[i]=(c[i]+e>=m);
        return(v);
    }
};
