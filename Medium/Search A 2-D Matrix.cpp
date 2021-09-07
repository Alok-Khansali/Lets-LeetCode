class Solution {                                                  //Modified Binary Search Algorithm
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i = 0,j = matrix[0].size() - 1;
        while(i < matrix.size() and j >= 0)
        {
            if(matrix[i][j] == target) 
                return true;
            else if(matrix[i][j] > target) 
                j--;
            else 
                i++;
        }
        return false;
    }
};
/*class Solution {                                                         Naive Approach
public:
    bool bs(vector<int> m,int t)
    {
        int i=0,j=m.size()-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(m[mid]==t)
                return true;
            else if(m[mid]>t)
                j=mid-1;
            else
                i=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && target > matrix[i][j])
             i++;
        if(i==matrix.size())
            return false;
        return bs(matrix[i],target);
    }
};
*/
