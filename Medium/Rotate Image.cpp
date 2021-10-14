class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        int n = matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j = i;j < n - i -1;j++)
            {
                int t = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = t;
            }
        }
    }
};
/*        //My first Approach 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j = i;j < n - i -1;j++)
            {
                swap(matrix[i][j],matrix[j][n-i-1]);
                swap(matrix[i][j],matrix[n-j-1][i]);
                swap(matrix[n-j-1][i],matrix[n-i-1][n-j-1]);
            }
        }
    }
};
*/
