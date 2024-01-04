class Solution // Approach 1 : full use of STL
{              // Runtime: 10 ms, faster than 52.10% of C++ online submissions for Reverse String II.
               // Memory Usage: 7.2 MB, less than 92.32% of C++ online submissions for Reverse String II.
public:
    string reverseStr(string s, int k)
    {
        int x = s.size(), i = 0;
        for (i = 0; i < x; i += 2 * k)
            reverse(s.begin() + i, s.begin() + i + min(k, x - i));
        return s;
    }
};