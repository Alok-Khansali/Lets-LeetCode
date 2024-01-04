class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        cin.tie(0);
        cout.tie(0);
        if(r*c != mat.size() * mat[0].size())
            return mat;
        vector<vector<int>> v(r,vector<int>(c));
        for(int i=0,x=0,y=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
            {
                v[x][y++]=mat[i][j];
                if(y==c)
                    x++,y=0;
            }
        return v;
    }
};
