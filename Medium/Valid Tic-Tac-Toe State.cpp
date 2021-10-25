class Solution {
public:
    bool winn(vector<string> brd,char c)  // Checking all vertical lines,horizontal lines and the two dialgonals to conclude a win
    {
        if((brd[0][0 ]== c && brd[1][0] == c&& brd[2][0] == c)||(brd[0][1] == c && brd[1][1]==c && brd[2][1] == c)
           ||(brd[0][2] == c && brd[1][2] == c && brd[2][2] == c)||(brd[0][0] == c && brd[0][1] == c && brd[0][2] == c)
           ||(brd[1][0] == c && brd[1][1] == c && brd[1][2] == c)||(brd[2][0] == c && brd[2][1] == c && brd[2][2] == c)
           ||(brd[0][0] == c && brd[1][1] == c && brd[2][2] == c)||(brd[0][2] == c && brd[1][1] == c && brd[2][0] == c)) 
        {
          return(true);
        }
        return(false);
    }
    bool validTicTacToe(vector<string>& board) 
    {
        int x = 0,o = 0;          //x tracks count of 'X'       and          o tracks the occurance of 'O'
        for(string s : board)
        {
            for(char c : s)
            {
                if( c == 'X')
                {
                    x++;
                }
                else if(c == 'O')
                {
                    o++;
                }
            }
        }
        if(x == o || x == o+1)      // the frequency of X in a valid game is either equal to the (frequency of O) or equal to (frequency of O +1)
        {
            bool win_x = winn(board,'X'),win_o = winn(board,'O');
            if(win_x)        // If X wins then surely O shouldn't win in a valid game
            {
                if(win_o)       //If O wins then surely board is invalid
                {
                    return false;
                }
                return (x == o + 1);         //If X wins then surely the frequency of X is = Frequency of O  (AS X played first)
            }
            if(win_o)           //If O wins then surely the frequency of O is = Frequency of X  (AS O played second, it can't play more moves than X)
            {
                return (x == o);
            }
            return true;     //If nobdy wins then its a valid board, as the frequency condition is satisfied
        }
        return false;    
    }
};
