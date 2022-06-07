class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
  // Memory Usage: 5.9 MB, less than 98.99% of C++ online submissions for Reverse Only Letters.
public:
    string reverseOnlyLetters(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (isalpha(s[i]) && isalpha(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else
            {
                if (!isalpha(s[i]))
                    i++;
                if (!isalpha(s[j]))
                    --j;
            }
        }
        return s;
    }
};