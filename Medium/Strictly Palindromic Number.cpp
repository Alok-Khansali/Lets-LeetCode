class Solution // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Strictly Palindromic Number.
// Memory Usage: 5.7 MB, less than 99.35% of C++ online submissions for Strictly Palindromic Number.
{
public:
    bool isStrictlyPalindromic(int n)
    {
        // No matter what you do, at base(n-2), number wont be palindrome
        /*
        Q: Why always false?
        A. The n-2 case will always fail for n >= 4:
        n = 1*(n-2) + 2 --> n = "12" (base n-2)
        */
        return false;
    }
};