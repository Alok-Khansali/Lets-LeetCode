class Solution // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Break a Palindrome.
               // Memory Usage: 6.3 MB, less than 5.00% of C++ online submissions for Break a Palindrome.
{
public:
    string breakPalindrome(string palindrome)
    {
        ios_base::sync_with_stdio(0);
        int l = palindrome.size();
        // A single letter entry can't be broken in any way such that it doesnt stay a palindrome
        // Hence return ""
        if (l == 1)
            return "";
        // Now the remaining task to find a position that doesn't contain 'a'
        for (int i = 0; i < l; i++)
            if (palindrome[i] != 'a')
            {
                if ((l & 1) && i == l / 2)
                    break;
                palindrome[i] = 'a';
                return palindrome;
            }
        // In a case where
        // We have all 'a's,
        // Or when replacing a char in the middle makes the string palindrome again
        // Just replace b at the end
        palindrome[l - 1] = 'b';
        return palindrome;
    }
};