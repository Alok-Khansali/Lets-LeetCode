/*
For in place transformation, numbers hv to be modified smartly
0 to 0, dont change
0 t0 1, change it to 2
1 to 1, dont change
1 to 0, change it to 3

Once all is said and done, reuse the codes to get the actual values
For 1s I have used odd number because my logic uses & operator to get the neighbouring sum
For 0s I have used even numbers as they won't participate in the addition 
If Live neighbours are 2, nothing changes
If Live neighbours are exactly then, dead changes to live, while live stays as it it
If live neighbours are greater than 3 or less than 2, dead state is not affected but live changes to dead


Algorithm
Step 1: Check for live neighbours
Step 2: Check Conditions and code the current value as per your logic
Step 3: Repeat 2 and 3 until all the elements are correctly coded
Step 4: Decode the values and change them
Step 5: Return the answer

*/
class Solution {   // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
                   // Memory Usage: 6.8 MB, less than 84.44% of C++ online submissions for Game of Life.
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size(),n = board[0].size();
        for(int i = 1;i< m-1;i++)                       //Breaking the code into parts, solving the non boundary elements first
            for(int j = 1;j< n-1;j++)
            {
                int c = (board[i][j+1] & 1) + (board[i+1][j+1] & 1) + (board[i-1][j+1] & 1) + (board[i+1][j] & 1) 
                     + (board[i-1][j] & 1) + (board[i][j-1] & 1) + (board[i-1][j-1] & 1) + (board[i+1][j-1] & 1);
                if(c < 2 || c > 3)
                {
                    if(board[i][j])
                        board[i][j] = 3;                                    
                }
                else if(c == 3)
                {
                    if(board[i][j] == 0)
                        board[i][j] = 2;
                }
            }
        
        for(int i = 0;i<m;i++)           //A left or right Cornered element can have atmost 5 Neighbours
        {
            int c = 0;
            if(n > 1)
                c += (board[i][1] & 1);    //To the right
            if(n > 1 && i+1 < m)
                c += (board[i+1][1] & 1);  //bottom right
            if(n > 1 && i > 0)
                c += (board[i-1][1] & 1);  //top right
            if(i > 0)
                c += (board[i-1][0] & 1);  //top
            if(i+1 < m)
                c += (board[i+1][0] & 1);  //bottom
            
            if(c < 2 || c > 3)             //Left cornered Element
            {
                    if(board[i][0] & 1)
                        board[i][0] = 3;                                    
            }
            else if(c == 3)
            {
                    if(board[i][0] == 0)
                        board[i][0] = 2;
            }
            c = 0;
            if(n > 1)
                c += (board[i][n-2] & 1);    //To the left
            if(n > 1 && i+1 < m)
                c += (board[i+1][n-2] & 1);  //bottom left
            if(n > 1 && i > 0)
                c += (board[i-1][n-2] & 1);  //top left
            if(i > 0)
                c += (board[i-1][n-1] & 1);  //top
            if(i+1 < m)
                c += (board[i+1][n-1] & 1);  //bottom
            
            if(c < 2 || c > 3)             //Right cornered Element
            {
                    if(board[i][n-1] & 1)
                        board[i][n-1] = 3;                                    
            }
            else if(c == 3)
            {
                    if(board[i][n-1] == 0)
                        board[i][n-1] = 2;
            }
        }
        for(int i = 0;i<n;i++)           //A top or bottom row element can have atmost 5 Neighbours
        {
            int c = 0;
            if(m > 1)                      //bottom
                c += (board[1][i] & 1);    
            if(m > 1 && i+1 < n) 
                c += (board[1][i+1] & 1);  //bottom left
            if(m > 1 && i > 0)
                c += (board[1][i-1] & 1);  //bottom right
            if(i+1 < n)
                c += (board[0][i+1] & 1);  //right
            if(i > 0)
                c += (board[0][i-1] & 1);  //left
            
            if(c < 2 || c > 3)             //top row Element
            {
                    if(board[0][i] & 1)
                        board[0][i] = 3;                                    
            }
            else if(c == 3)
            {
                    if(board[0][i] == 0)
                        board[0][i] = 2;
            }
            c = 0;
            if(m > 1)                      
                c += (board[m-2][i] & 1);    //top
            if(m > 1 && i+1 < n)
                c += (board[m-2][i+1] & 1);  //top
            if(m > 1 && i > 0)
                c += (board[m-2][i-1] & 1);  //top
            if(i+1 < n)
                c += (board[m-1][i+1] & 1);  //rigth
            if(i > 0)
                c += (board[m-1][i-1] & 1);  //left
            
            if(c < 2 || c > 3)             //bottom row Element
            {
                    if(board[m-1][i] & 1)
                        board[m-1][i] = 3;                                    
            }
            else if(c == 3)
            {
                    if(board[m-1][i] == 0)
                        board[m-1][i] = 2;
            }
        }
        //Time to decode, Reverse Engineering
        
        for(int i = 0 ;i < m;i++)                       
            for(int j = 0; j < n;j++)
            {
                if(board[i][j] == 3)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
    }
};