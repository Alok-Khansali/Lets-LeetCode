class Solution {   //Runtime: 19 ms, faster than 99.96% of C++ online submissions for Valid Palindrome II.
                   //Memory Usage: 24.9 MB, less than 15.73% of C++ online submissions for Valid Palindrome II.
public:
    bool chc(string s, int j ,int i)
    {
        while(i < j)                  //Checking if Palindrome
        {
             if(s[i] != s[j])
                 return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int j = s.size() - 1,i = 0;
        while(i < j)
        {
            if(s[i] == s[j])                  //If the Palindrome Condition is satisfied, increment i and decrement j by 1
                ++i,--j;
            else                              //Else Check if excluding the i(th) char, palindrome can be formed OR if Excluding the j(th ) char , palindrome can be formed
                return (chc(s,j,i+1) | chc(s,j-1,i)); 
        }
        return true;    //If the string was already a palindrome, the loop  will execute completely
    }
};
/*
N = Number of characters in the string or the string length
Time Complexity : O(N)    , Best Case : O(N/2)
Space Complexity : O(1)
*/


/*
class Solution {   //Runtime: 19 ms, faster than 99.96% of C++ online submissions for Valid Palindrome II.
                   //Memory Usage: 24.8 MB, less than 15.73% of C++ online submissions for Valid Palindrome II.
public:
    bool chc(string s, int j ,int i)
    {
        while(i < j)                  //Checking if Palindrome
        {
             if(s[i] != s[j])
                 return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int j = s.size() - 1,i = 0;
        while(i < j)
        {
            if(s[i] != s[j])                                //If characters are different,Check if excluding the i(th) char, palindrome can be formed OR if Excluding the j(th ) char , palindrome can be formed
                return (chc(s,j,i+1) | chc(s,j-1,i)); 
                ++i,--j;
        }
        return true;    //If the string was already a palindrome, the loop  will execute completely
    }
};
*/