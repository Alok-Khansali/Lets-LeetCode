class Solution {                              //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
                                              //Memory Usage: 6.5 MB, less than 85.87% of C++ online submissions for Spiral Matrix II.
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int r=0,i=0,j=0,c=0;
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int k = 1;k<=n/2;k++,c++)                     // Filling the matrix in squares, first outermost and then going inwards
        {
          for(i = c;i<n-c -1;i++)                         // Going from first element of the square to the second last in that row         
              v[c][i] = ++r;
          for(j = c;j<n-c -1;j++)                         //going from the last row element(first in the column) to the second last in that column
              v[j][i] = ++r;
          for(;i>c;i--)                                   //From the last element in the last column(last row element) to the second element in the bottom row
              v[j][i] = ++r;
          for(;j>c;j--)                                   //From the last element in the last row,(last column element) to the second element in the first column
              v[j][i] = ++r;
        }
        if(n&1)                                           // If the order of matrix is odd set the maximum in the center
            v[n/2][n/2] = ++r;
        return v;
    }
};
