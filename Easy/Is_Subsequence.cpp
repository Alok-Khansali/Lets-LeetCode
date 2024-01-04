class Solution {                                   //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
public:
    bool isSubsequence(string s, string t)
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
      
        if(s == t)                                 // If the strings are equal, s is definitely a subsequence of t
            return true;
        int p = 0, l = s.size();
      
        for(char c : t)
        {
            if(s[p] == c)
            {
                p++;
            }
            if(p == l)                           //Checking if all the characters of s have been matched in t
            {
                return true;
            }
        }
      
        return false;
    }
};
