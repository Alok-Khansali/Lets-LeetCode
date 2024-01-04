class Solution { //Runtime: 12 ms, faster than 99.43% of C++ online submissions for Minimum Remove to Make Valid 
                 //Memory Usage: 11 MB, less than 66.20% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
public:
    string minRemoveToMakeValid(string s) 
    {
       ios_base::sync_with_stdio(false);
	   cin.tie(NULL);
       string ans = "";
       int ob = 0,cb = 0,x = 0, y = 0;
       for(char c : s)                          //First Pass
       {
           if(c == '(')                         //Count the Number of opening brackets
               ++ob;
           else if(c == ')' && ob > cb)         //Count the closing brackets if they are valid, i.e number of  closing brackets < number of opening brackets
               ++cb; 
       }
       for(char c : s)                          //Second Pass
       {
           if(c == '(')                         //Opening bracket 
           {
               if(x+1 <= cb )                   //
               {
                   ans += c;
                   x++;
               }
           }
           else if(c == ')')
           {
               if(y+1 <= x)
               {
                   ans += c;
                   ++y;
               }
           }
           else 
               ans += c;
       }
        return ans;
    }
};
//Time complexity : O(N + N) = O(N)
//Space Complexity : O()