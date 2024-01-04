class Solution { //Runtime: 14 ms, faster than 90.60 %% of C++ online submissions for Stone Game IV.
public:
    bool winnerSquareGame(int n) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        vector<bool> dp(n+1,false);
        for(int i = 0;i <= n ;i++)
        {
            if(!dp[i])
              for(int k = 1;k<= sqrt(n-i);k++)
                dp[i + k*k] = true;                       //All square number position are made true, and the 
                                                          //The positions that gaurantees Alice's Win are Tabulated
        }
        return dp[n];                                     //If N is a win position, return true, else it will remain false
    }
};