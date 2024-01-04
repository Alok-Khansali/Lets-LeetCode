class Solution {    //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
public:
    bool detectCapitalUse(string word) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int t = word.size(),c = 0,f = -1;            //Taking the length of the word, A counter to track Caps
        for(int i = 0;i < t;i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')     //Counting the Number of Capitals
            {
                c++;
                f = i;                               //If Only only one Capital Letter, f should be 0;
            }
        }
        return(c == 1 &&  f == 0 || c == 0 || c == t); //If (only one caps, 0 caps or all caps), return true
    }
};
/*
Time Complexity O(N)
Space Complexity O(1)
*/
