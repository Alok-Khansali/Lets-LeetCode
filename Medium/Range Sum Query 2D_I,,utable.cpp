//Vector Stuff always takes more time, plus I used so many if conditions
class NumMatrix  //Runtime: 806 ms, faster than 17.08% of C++ online submissions for Range Sum Query 2D - Immutable.
                //Memory Usage: 148.1 MB, less than 21.70% of C++ online submissions for Range Sum Query 2D - Immutable.
{
public:
    vector<vector<int>> mtr;
    NumMatrix(vector<vector<int>> &matrix)
    {
        mtr = matrix;
        for (int i = 0; i < mtr.size(); i++)
            for (int j = 1; j < mtr[0].size(); j++)
                mtr[i][j] += mtr[i][j - 1];
        for (int i = 0; i < mtr[0].size(); i++)
            for (int j = 1; j < mtr.size(); j++)
                mtr[j][i] += mtr[j - 1][i];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if(row1 > 0 && col1 > 0)
           return  ( mtr[row2][col2] +  mtr[row1 - 1][col1 - 1] - mtr[row2][col1 - 1] - mtr[row1 - 1][col2] );
        else if(col1 > 0)
           return (mtr[row2][col2] -  mtr[row2][col1 - 1]); 
        else if(row1 > 0)
           return ( mtr[row2][col2] - mtr[row1 - 1][col2]); 
        return mtr[row2][col2];
    }
};

//changing the data structure, to get better time complexity
class NumMatrix  //Runtime: 447 ms, faster than 87.32% of C++ online submissions for Range Sum Query 2D - Immutable.
                 //Memory Usage: 149.4 MB, less than 18.41% of C++ online submissions for Range Sum Query 2D - Immutable.
{
public:
    int mtr[201][201];
    NumMatrix(vector<vector<int>> &matrix)
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        memset(mtr,0,sizeof(mtr));
        for (int i = 1; i <= matrix.size(); i++)           //Row - wise summation
            for (int j = 1; j <= matrix[0].size(); j++)
                mtr[i][j] += mtr[i][j - 1] + matrix[i-1][j - 1];
         
        for (int i = 1; i <= matrix[0].size(); i++)        //Column wise summation
            for (int j = 2; j <= matrix.size(); j++)
                mtr[j][i] += mtr[j-1][i];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        ios_base::sync_with_stdio(false);
           return  ( mtr[row2+1][col2+1] +  mtr[row1][col1] - mtr[row2+1][col1] - mtr[row1][col2+1] );
    }
};