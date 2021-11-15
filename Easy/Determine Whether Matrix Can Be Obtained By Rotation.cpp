class Solution {              //Runtime: 4 ms, faster than 83.33% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
public:
    //We need to check three rotations in the worst case,each time rotate the matrix 90 clockwise.
    int n;
    void rotate(vector<vector<int>>& matrix)                              //Function to rotate the matrix by 90 degree      
    {
        ios_base::sync_with_stdio(false);
        int n = matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j = i;j < n - i -1;j++)
            {
                int t = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];                         //Swapping 4 values in one go
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = t;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        ios_base::sync_with_stdio(false);
        n = mat.size();
                  
        if(mat == target)                     //It may be possible that matrices are already identical, i.e. 360 degree rotation
        {
            return true;
        }
        else                                  //If matrices are different, then rotate matrix by 90 degree
        { 
            rotate(mat);                         
            if(mat == target)                 //Check if target matrix can be achieved rotating the given matrix by 90 degree
            {
                return true;
            }
            rotate(mat);                      //If matrices are different, then rotate matrix by 90 degree        
            
            if(mat == target)                 //Check if target matrix can be achieved rotating the given matrix by 180 degree
            {
                return true;
            }
            rotate(mat);                      //If matrices are different, then rotate matrix by 90 degree,now matrix has been rotated by 270 degrees   
        }
        return mat == target;                 //if the taregt matrix can't be achieved even after 3 three rotations, then it is impossible to make (mat = target) by rotation
    } 
};
