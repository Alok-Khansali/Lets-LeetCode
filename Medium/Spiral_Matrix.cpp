class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) 
    {
        int l = m.size() - 1, x = m[0].size() - 1;
        if(m.size()==1)
            return m[0];
        vector<int> v;
        for(int i=0,j=0;(i<=l && j<=x);i++,j++,l--,x--)
        {
            for(int k = j; k <= x; k++) 
                v.push_back(m[i][k]);

            for(int k = i+1; k<= l; k++)
                v.push_back(m[k][x]);

            if(i<l && j<x) 
            {
                for(int k=x-1; k>j; k--) 
                   v.push_back(m[l][k]);

                for(int k=l; k>i; k--) 
                    v.push_back(m[k][j]);
            }
        }
        return v;
    }
};